// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _RESIZING_ARRAY_STACK_
#define _RESIZING_ARRAY_STACK_

#include <iostream>

#include "resizing_array.h"

namespace algs4 {
template <typename T>
class ResizingArrayStack {
 public:
  using self = ResizingArrayStack<T>;
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using difference_type = ptrdiff_t;
  using size_type = size_t;
  using iterator = typename ResizingArray<T>::reverse_iterator;
  using const_iterator = typename ResizingArray<T>::const_reverse_iterator;

  ResizingArrayStack() : ra(ResizingArray<T>()) {}

  iterator begin() { return ra.rbegin(); }
  iterator end() { return ra.rend(); }
  const_iterator begin() const { return ra.rbegin(); }
  const_iterator end() const { return ra.rend(); }
  const_iterator cbegin() const { return ra.crbegin(); }
  const_iterator cend() const { return ra.crend(); }

  void push(const_reference x) { ra.pushBack(x); }

  value_type pop() {
    value_type ret;
    try {
      ret = ra.back();
      ra.popBack();
    } catch (const std::out_of_range& e) {
      std::cerr << "Stack overflow!" << std::endl;
      abort();
    }
    return ret;
  }

  bool isEmpty() { return size() == 0; }
  size_type size() { return ra.size(); }

 private:
  ResizingArray<T> ra;

 public:
  static void MainTest(int argc = 0, char* argv[] = nullptr) {
    using std::cout;
    using std::endl;

    ResizingArrayStack<int> ras1;
    for (int i = 0; i < 5; ++i) {
      ras1.push(i);
    }
    cout << "ras1 contains " << ras1.size() << " elements:" << endl;
    for (const auto& x : ras1) {
      cout << x << " ";
    }
    cout << endl;
    ResizingArrayStack<int> ras2(ras1);
    cout << "ras2 contains " << ras2.size() << " elements:" << endl;
    for (const auto& x : ras2) {
      cout << x << " ";
    }
    cout << endl;
    cout << "Pop from ras2: " << ras2.pop() << endl;
    cout << "Pop from ras2: " << ras2.pop() << endl;
    cout << "Pop from ras2: " << ras2.pop() << endl;
    cout << "Pop from ras2: " << ras2.pop() << endl;
    cout << "Pop from ras2: " << ras2.pop() << endl;
    cout << "ras2 contains " << ras2.size() << " elements." << endl;
    ResizingArrayStack<int> ras3(ras1);
    cout << "ras3 copy from ras1:" << endl;
    for (const auto& x : ras3) {
      cout << x << " ";
    }
    cout << endl;
    ResizingArrayStack<int> ras4 = ras1;
    cout << "ras4 assign from ras1:" << endl;
    for (const auto& x : ras4) {
      cout << x << " ";
    }
    cout << endl;
    ResizingArrayStack<int> ras5(std::move(ras3));
    cout << "ras5 move from ras3:" << endl;
    for (const auto& x : ras5) {
      cout << x << " ";
    }
    cout << endl;
  }
};
}  // namespace algs4
#endif