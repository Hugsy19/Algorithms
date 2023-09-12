// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <initializer_list>
#include <iterator>
#include <memory>
#include <exception>

namespace algs4 {
template <typename T>
class Queue;

template <typename T>
void swap(Queue<T>&, Queue<T>&);

template <typename T>
class Queue {
  friend void swap<T>(Queue<T>&, Queue<T>&);

 public:
  struct Node {
    T data;
    Node* next;
  };

  struct Iterator {
    using self = Iterator;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    Iterator() : curr(nullptr) {}

    explicit Iterator(Node* p) : curr(p) {}

    reference operator*() const { return curr->data; }

    pointer operator->() const { return &this->operator*(); }

    self& operator++() {
      curr = curr->next;
      return *this;
    }

    self operator++(int) {
      self ret = *this;
      curr = curr->next;
      return ret;
    }

    friend bool operator==(const self& lhs, const self& rhs) {
      return lhs.curr == rhs.curr;
    }

    friend bool operator!=(const self& lhs, const self& rhs) {
      return !(lhs == rhs);
    }

   private:
    Node* curr;
  };

  struct ConstIterator {
    using self = ConstIterator;
    using value_type = T;
    using pointer = const T*;
    using reference = const T&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    ConstIterator() : curr(nullptr) {}

    explicit ConstIterator(Node* p) : curr(p) {}

    reference operator*() const { return curr->data; }

    pointer operator->() const { return &this->operator*(); }

    self& operator++() {
      curr = curr->next;
      return *this;
    }

    self operator++(int) {
      self ret = *this;
      curr = curr->next;
      return ret;
    }

    friend bool operator==(const self& lhs, const self& rhs) {
      return lhs.curr == rhs.curr;
    }

    friend bool operator!=(const self& lhs, const self& rhs) {
      return !(lhs == rhs);
    }

   private:
    const Node* curr;
  };

  using self = Queue<T>;
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using difference_type = ptrdiff_t;
  using size_type = size_t;
  using iterator = Iterator;
  using const_iterator = ConstIterator;

  Queue() : first(nullptr), last(nullptr), sz(0) {}

  Queue(std::initializer_list<T> il) : Queue() {
    rangeInitialize(il.begin(), il.end());
  }

  Queue(const self& q) : Queue() { rangeInitialize(q.begin(), q.end()); }

  Queue(self&& q) : first(q.first), last(q.last), sz(q.sz) {
    q.first = nullptr;
    q.last = nullptr;
    q.sz = 0;
  }

  self& operator=(self rhs) {
    swap(*this, rhs);
    return *this;
  }

  iterator begin() { return iterator(first); }
  iterator end() { return iterator(); }
  const_iterator begin() const { return const_iterator(first); }
  const_iterator end() const { return const_iterator(); }
  const_iterator cbegin() const { return const_iterator(first); }
  const_iterator cend() const { return const_iterator(); }

  void enqueue(const_reference x) {
    Node* oldLast = last;
    last = createNode(x);
    last->next = nullptr;
    if (isEmpty())
      first = last;
    else
      oldLast->next = last;
    ++sz;
  }

  value_type dequeue() {
    value_type ret;
    if (first) {
      ret = first->data;
      Node* tmp = first;
      first = first->next;
      destroyNode(tmp);
      if (isEmpty()) last = nullptr;
      --sz;
    } else {
      throw std::out_of_range("Queue overflow");
    }
    return ret;
  }

  bool isEmpty() { return first == nullptr; }
  size_type size() { return sz; }

 private:
  Node *first, *last;
  size_type sz;
  static std::allocator<Node> alloc;

  Node* createNode(const_reference x) {
    Node* ret = alloc.allocate(1);
    alloc.construct(&ret->data, x);
    return ret;
  }

  template <typename ForwardIterator>
  void rangeInitialize(ForwardIterator beg, ForwardIterator ed) {
    Node* oldLast = nullptr;
    for (; beg != ed; ++beg) {
      last = createNode(*beg);
      last->next = nullptr;
      if (isEmpty()) {
        first = last;
      } else {
        oldLast->next = last;
      }
      oldLast = last;
      ++sz;
    }
  }

  void destroyNode(Node* n) {
    alloc.destroy(&n->data);
    alloc.deallocate(n, 1);
  }

  void clear() {
    while (first) {
      Node* tmp = first;
      first = first->next;
      destroyNode(tmp);
    }
  }

 public:
  static void MainTest(int argc = 0, char* argv[] = nullptr) {
    using std::cout;
    using std::endl;

    Queue<int> q1;
    for (int i = 0; i < 5; ++i) {
      q1.enqueue(i);
    }
    cout << "q1 contains " << q1.size() << " elements:" << endl;
    for (const auto& x : q1) {
      cout << x << " ";
    }
    cout << endl;
    cout << "Dequeue form q1: " << q1.dequeue() << endl;
    cout << "Dequeue form q1: " << q1.dequeue() << endl;
    cout << "Dequeue form q1: " << q1.dequeue() << endl;
    cout << "Dequeue form q1: " << q1.dequeue() << endl;
    cout << "q1 contains " << q1.size() << " elements." << endl;
    Queue<int> q2{6, 7, 8, 9, 10};
    cout << "q2 contains " << q2.size() << " elements:" << endl;
    for (const auto& x : q2) {
      cout << x << " ";
    }
    cout << endl;
    Queue<int> q3(q1);
    cout << "q3 copy from q1:" << endl;
    for (const auto& x : q3) {
      cout << x << " ";
    }
    cout << endl;
    q3 = q2;
    cout << "q3 assign from q2:" << endl;
    for (const auto& x : q3) {
      cout << x << " ";
    }
    cout << endl;
    Queue<int> q4(std::move(q3));
    cout << "q4 move from q3:" << endl;
    for (const auto& x : q4) {
      cout << x << " ";
    }
    cout << endl;
  }
};

template <typename T>
std::allocator<typename Queue<T>::Node> Queue<T>::alloc;

template <typename T>
void swap(Queue<T>& lhs, Queue<T>& rhs) {
  using std::swap;
  swap(lhs.first, rhs.first);
  swap(lhs.last, rhs.last);
  swap(lhs.sz, rhs.sz);
}
}  // namespace algs4
#endif