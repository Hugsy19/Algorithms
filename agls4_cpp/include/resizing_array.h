// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _RESIZING_ARRAY_
#define _RESIZING_ARRAY_

#include <memory>
#include <iterator>

namespace algs4 {
template <typename T, typename Alloc = std::allocator<T>>
class ResizingArray {
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


};
}  // namespace algs4

#endif