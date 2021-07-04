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
};
}  // namespace algs4
#endif