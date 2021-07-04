// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _RESIZING_ARRAY_STACK_
#define _RESIZING_ARRAY_STACK_

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
  using iterator = typename ResizingArray<T>::iterator;
  using const_iterator = typename ResizingArray<T>::const_iterator;

  
};
}  // namespace algs4
#endif