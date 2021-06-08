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

  bool isEmpty() { return sll.isEmpty(); }
  size_type size() { return sll.size(); }

  void add(const_reference x) { sll.insert(x); }

 private:
  SingleLinkedList<T> sll;
};
}  // namespace algs4
#endif