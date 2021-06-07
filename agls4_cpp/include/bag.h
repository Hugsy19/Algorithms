// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _BAG_H_
#define _BAG_H_

#include <memory>
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
  using iterator = single_linked_list::Iterator<T>;
  using const_iterator = single_linked_list::ConstIterator<T>;

  Bag() : first(nullptr), sz(0) {}
  Bag(std::initializer_list<T> il) {
    for (const auto &x : il) {
      add(x);
    }
  }

  Bag(const self& bg) {

  }
  self& operator=(const self& rhs) {

  }

  ~Bag() { clear(); }

  iterator begin() { return iterator(first); }
  iterator end() { return iterator(); }
  const_iterator begin() const { return const_iterator(first); }
  const_iterator end() const { return const_iterator(); }
  const_iterator cbegin() const { return const_iterator(first); }
  const_iterator cend() const { return const_iterator(); }

  bool isEmpty() { return first == nullptr; }
  size_type size() { return sz; }

  void add(const_reference x) {
    bag_node* old_first = first;
    first = createNode(x);
    first->next = old_first;
    ++sz;
  }

 private:
  using bag_node = single_linked_list::Node<T>;

  bag_node* first;
  size_type sz;
  static std::allocator<bag_node> alloc;

  bag_node* createNode(const value_type& x) {
    bag_node* node = alloc.allocate(1);
    alloc.construct(&node->data, x);
    return node;
  }
  
  void destroyNode(bag_node* node) {
    alloc.destroy(&node->data);
    alloc.deallocate(node, 1);
  }

  void clear() {
    while (first) {
      bag_node* tmp = first;
      first = first->next;
      destroyNode(tmp);
    }
  }
};

template <typename T>
std::allocator<typename Bag<T>::bag_node> Bag<T>::alloc;

}  // namespace algs4
#endif