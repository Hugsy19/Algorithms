// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _RESIZING_ARRAY_
#define _RESIZING_ARRAY_

#include <iterator>
#include <memory>

namespace algs4 {
template <typename T>
class ResizingArray;

template <typename T>
void swap(ResizingArray<T>&, ResizingArray<T>&);

template <typename T>
class ResizingArray {
  friend void swap<T>(ResizingArray<T>&, ResizingArray<T>&);

 public:
  using self = ResizingArray<T>;
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  using iterator = pointer;
  using const_iterator = const_pointer;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  ResizingArray() : beg(nullptr), ed(nullptr), cap(nullptr) {}

  ResizingArray(std::initializer_list<T> il) {
    auto newMem = allocCopy(il.begin(), il.end());
    beg = newMem.first;
    cap = ed = newMem.second;
  }

  ResizingArray(const self& ra) {
    auto newMem = allocCopy(ra.begin(), ra.end());
    beg = newMem.first;
    cap = ed = newMem.second;
  }

  ResizingArray(self&& ra) : beg(ra.beg), ed(ra.ed), cap(ra.cap) {
    ra.beg = ra.ed = ra.cap = nullptr;
  }

  self& operator=(self rhs) {
    swap(*this, rhs);
    return *this;
  }

  ~ResizingArray() { free(); }

  reference operator[](size_type n) { return beg[n]; }
  const_reference operator[](size_type n) const { return beg[n]; }

  iterator begin() { return beg; }
  iterator end() { return ed; }
  const_iterator begin() const { return beg; }
  const_iterator end() const { return ed; }
  const_iterator cbegin() const { return beg; }
  const_iterator cend() const { return ed; }

  reverse_iterator rbegin() { return reverse_iterator(ed); }
  reverse_iterator rend() { return reverse_iterator(beg); }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(ed); }
  const_reverse_iterator rend() const { return const_reverse_iterator(beg); }
  const_reverse_iterator crbegin() const { return const_reverse_iterator(ed); }
  const_reverse_iterator crend() const { return const_reverse_iterator(beg); }

  void pushBack(const_reference x) {
    realloc();
    alloc.construct(ed++, std::move(x));
  }

  void popBack() {
    if (first != nullptr) {
      alloc.destroy(--ed);
    }
    dealloc();
  }

  value_type front() { return *beg; }
  value_type back() { return *(ed - 1); }

  size_type size() { return ed - beg; }
  size_type capacity() { return cap - beg; }

  void reserve(size_type sz) {
    if (sz < capacity()) return;
    allocMove(sz);
  }

  void resize(size_type sz) {
    if (sz > size()) {
      if (sz > capacity()) allocMove(sz);
      for (size_type i = size(); i < sz; ++i) {
        alloc.construct(ed++, T());
      }
    } else if (sz < size()) {
      while (ed != beg + sz) {
        alloc.destroy(--ed);
      }
    }
  }

 private:
  pointer beg, ed, cap;
  static std::allocator<T> alloc;

  std::pair<pointer, pointer> allocCopy(const_iterator b, const_iterator e) {
    pointer data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
  }

  void allocMove(size_type sz) {
    pointer newBeg = alloc.allocate(sz);
    pointer newEnd = newBeg;
    pointer oldBeg = beg;
    for (size_type i = 0; i < size(); ++i) {
      alloc.construct(newEnd++, std::move(*oldBeg++));
    }
    free();
    beg = newBeg;
    ed = newEnd;
    cap = newBeg + sz;
  }

  void realloc() {
    if (size() == capacity()) {
      size_type newCap = size() ? 2 * size() : 1;
      allocMove(newCap);
    }
  }

  void dealloc() {
    if (size() == capacity() / 4) {
      size_type newCap = capacity() / 2;
      allocMove(newCap);
    }
  }

  void free() {
    if (beg) {
      for (pointer p = ed; p != beg;) {
        alloc.destroy(--p);
      }
      alloc.deallocate(beg, cap - beg);
    }
  }

 public:
  static void MainTest(int argc = 0, char* argv[] = nullptr) {
    using std::cout;
    using std::endl;

    ResizingArray<int> ra1;
    for (int i = 0; i < 5; ++i) {
      ra1.pushBack(i);
    }
    cout << "ra1 contains " << ra1.size() << " elements:" << endl;
    cout << "the first elements of ra1: " << ra1.front() << endl;
    cout << "the last elements of ra1: " << ra1.back() << endl;
    for (const auto& x : ra1) {
      cout << x << " ";
    }
    cout << endl;
    ResizingArray<int> ra2;
    for (auto it = ra1.crbegin(); it != ra1.crend(); ++it) {
      ra2.pushBack(*it);
      cout << "ra2 contains " << ra2.size() << " elements." << endl;
      cout << "ra2 can contains " << ra2.capacity() << " elements at most."
           << endl;
    }
    for (size_type i = 0; i < ra2.size(); ++i) {
      cout << ra2[i] << " ";
    }
    cout << endl;
    for (size_type i = ra2.size(); i != 1; --i) {
      ra2.popBack();
      cout << "ra2 contains " << ra2.size() << " elements." << endl;
      cout << "ra2 can contains " << ra2.capacity() << " elements at most."
           << endl;
    }
    ra2.reserve(10);
    cout << "ra2 contains " << ra2.size() << " elements." << endl;
    cout << "ra2 can contains " << ra2.capacity() << " elements at most."
         << endl;
    ra2.resize(11);
    cout << "ra2 contains " << ra2.size() << " elements." << endl;
    cout << "ra2 can contains " << ra2.capacity() << " elements at most."
         << endl;
    ResizingArray<int> ra3{6, 7, 8, 9, 10};
    cout << "ra3 contains " << ra3.size() << " elements:" << endl;
    for (const auto& x : ra3) {
      cout << x << " ";
    }
    cout << endl;
    ResizingArray<int> ra4(ra3);
    cout << "ra4 copy from ra3:" << endl;
    for (const auto& x : ra4) {
      cout << x << " ";
    }
    cout << endl;
    ra4 = ra1;
    cout << "ra4 assign from ra1:" << endl;
    for (const auto& x : ra4) {
      cout << x << " ";
    }
    cout << endl;
    ResizingArray<int> ra5(std::move(ra3));
    cout << "ra5 move from ra3:" << endl;
    for (const auto& x : ra5) {
      cout << x << " ";
    }
    cout << endl;
  }
};

template <typename T>
std::allocator<T> ResizingArray<T>::alloc;

template <typename T>
void swap(ResizingArray<T>& lhs, ResizingArray<T>& rhs) {
  using std::swap;
  swap(lhs.beg, rhs.beg);
  swap(lhs.ed, rhs.ed);
  swap(lhs.cap, rhs.ed);
}
}  // namespace algs4

#endif