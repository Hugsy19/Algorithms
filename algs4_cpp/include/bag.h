// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _BAG_H_
#define _BAG_H_

#include "single_linked_list.h"

namespace algs4 {
template <typename T>
class Bag {
 public:
  using self = Bag<T>;
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using difference_type = ptrdiff_t;
  using size_type = size_t;
  using iterator = typename SingleLinkedList<T>::iterator;
  using const_iterator = typename SingleLinkedList<T>::const_iterator;

  Bag() : sll(SingleLinkedList<T>()) {}

  Bag(std::initializer_list<T> il) : sll(SingleLinkedList<T>(il)) {}

  iterator begin() { return sll.begin(); }
  iterator end() { return sll.end(); }
  const_iterator begin() const { return sll.begin(); }
  const_iterator end() const { return sll.end(); }
  const_iterator cbegin() const { return sll.cbegin(); }
  const_iterator cend() const { return sll.cend(); }

  bool isEmpty() { return size() == 0; }
  size_type size() { return sll.size(); }

  void add(const_reference x) { sll.insert(x); }

 private:
  SingleLinkedList<T> sll;
 public:
  static void MainTest(int argc = 0, char* argv[] = nullptr) {
    using std::cout;
    using std::endl;

    Bag<int> bag1;
    for (int i = 0; i < 5; ++i) {
        bag1.add(i);
    }
    cout << std::boolalpha << "Is bag1 empty? " << bag1.isEmpty()  << endl;
    cout << "bag1 contains " << bag1.size() << " elements:" << endl;
    for (const auto &x : bag1) {
        cout << x << " ";
    }
    cout << endl;
    Bag<int> bag2{6, 7, 8, 9, 10};
    cout << std::boolalpha << "Is bag2 empty? " << bag2.isEmpty()  << endl;
    cout << "bag2 contains " << bag2.size() << " elements:" << endl;
    for (const auto &x : bag2) {
        cout << x << " ";
    }
    cout << endl;
    Bag<int> bag3(bag1);
    cout << "bag3 copy from bag1:" << endl;
    for (const auto &x : bag3) {
        cout << x << " ";
    }
    cout << endl;
    bag3 = bag2;
    cout << "bag3 assign from bag2:" << endl;
    for (const auto &x : bag3) {
        cout << x << " ";
    }
    cout << endl;
    Bag<int> bag4(std::move(bag3));
    cout << "bag4 move from bag3:" << endl;
    for (const auto &x : bag4) {
        cout << x << " ";
    }
    cout << endl;
  }
};
}  // namespace algs4
#endif