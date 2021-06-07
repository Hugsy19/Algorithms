// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _SINGLE_LINKED_LIST_
#define _SINGLE_LINKED_LIST_

#include <iterator>

namespace algs4 {
namespace single_linked_list {

template <typename T>
struct Node {
  T data;
  Node* next;
};

template <typename T>
struct Iterator {
  using self = Iterator<T>;
  using value_type = T;
  using pointer = T*;
  using reference = T&;
  using difference_type = ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  Iterator() : curr(nullptr) {}
  explicit Iterator(node<T>* p) : curr(p) {}

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
  Node<T>* curr;
};

template <typename T>
struct ConstIterator {
  using self = ConstIterator<T>;
  using value_type = T;
  using pointer = const T*;
  using reference = const T&;
  using difference_type = ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  ConstIterator() : curr(nullptr) {}
  explicit ConstIterator(node<T>* p) : curr(p) {}

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
  const Node<T>* curr;
};
}  // namespace single_linked_list
}  // namespace algs4

#endif