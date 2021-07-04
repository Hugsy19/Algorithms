// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _STACK_H_
#define _STACK_H_

#include "single_linked_list.h"

namespace algs4 {
template <typename T>
class Stack {
 public:
  using self = Stack<T>;
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using difference_type = ptrdiff_t;
  using size_type = size_t;
  using iterator = typename SingleLinkedList<T>::iterator;
  using const_iterator = typename SingleLinkedList<T>::const_iterator;

  Stack() : sll(SingleLinkedList<T>()) {}

  Stack(std::initializer_list<T> il) : sll(SingleLinkedList<T>(il)) {}

  iterator begin() { return sll.begin(); }
  iterator end() { return sll.end(); }
  const_iterator begin() const { return sll.begin(); }
  const_iterator end() const { return sll.end(); }
  const_iterator cbegin() const { return sll.cbegin(); }
  const_iterator cend() const { return sll.cend(); }

  void push(const_reference x) { sll.pushFront(x); }

  value_type pop() {
    value_type ret;
    if (!isEmpty()) {
      ret = sll.front();
      sll.popFront();
    }
    return ret;
  }

  bool isEmpty() { return size() == 0; }
  size_type size() { return sll.size(); }

 private:
  SingleLinkedList<T> sll;

 public:
  static void MainTest(int argc = 0, char* argv[] = nullptr) {
    using std::cout;
    using std::endl;

    Stack<int> s1;
    for (int i = 0; i < 5; ++i) {
      s1.push(i);
    }
    cout << "s1 contains " << s1.size() << " elements:" << endl;
    for (const auto& x : s1) {
      cout << x << " ";
    }
    cout << endl;
    Stack<int> s2{6, 7, 8, 9, 10};
    cout << "s2 contains " << s2.size() << " elements:" << endl;
    for (const auto& x : s2) {
      cout << x << " ";
    }
    cout << endl;
    cout << "Pop from s2: " << s2.pop() << endl;
    cout << "Pop from s2: " << s2.pop() << endl;
    cout << "Pop from s2: " << s2.pop() << endl;
    cout << "Pop from s2: " << s2.pop() << endl;
    cout << "Pop from s2: " << s2.pop() << endl;
    cout << "Pop from s2: " << s2.pop() << endl;
    cout << "s2 contains " << s2.size() << " elements." << endl;
    Stack<int> s3(s1);
    cout << "s3 copy from s1:" << endl;
    for (const auto& x : s3) {
      cout << x << " ";
    }
    cout << endl;
    Stack<int> s4 = s1;
    cout << "s4 assign from s1:" << endl;
    for (const auto& x : s4) {
      cout << x << " ";
    }
    cout << endl;
    Stack<int> s5(std::move(s3));
    cout << "s5 move from s3:" << endl;
    for (const auto& x : s5) {
      cout << x << " ";
    }
    cout << endl;
  }
};
}  // namespace algs4
#endif