// Copyright(c) 2021-present, Hugsy19 & algs4_cpp contributors.
// Licensed under the Apache License, Version 2.0.

#ifndef _SINGLE_LINKED_LIST_
#define _SINGLE_LINKED_LIST_

#include <initializer_list>
#include <iterator>
#include <memory>

namespace algs4 {
template <typename T>
class SingleLinkedList {
 public:
  using self = SingleLinkedList<T>;
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

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

  using iterator = Iterator;
  using const_iterator = ConstIterator;

  SingleLinkedList() : first(nullptr), sz(0) {}
  SingleLinkedList(std::initializer_list<T> il) {
    rangeInitialize(il.begin(), il.end());
  }

  SingleLinkedList(const self& sll) {
    rangeInitialize(sll.beign(), sll.end());
  }

  self& operator=(const self& rhs) {
    clear();
    rangeInitialize(rhs.begin(), rhs.end());
  }

  iterator begin() { return iterator(first); }
  iterator end() { return iterator(); }
  const_iterator begin() const { return const_iterator(first); }
  const_iterator end() const { return const_iterator(); }
  const_iterator cbegin() const { return const_iterator(first); }
  const_iterator cend() const { return const_iterator(); }

  bool isEmpty() { return first == nullptr; }
  size_type size() { return sz; }

  void insert(const_reference x) {
    Node* oldFirst = first;
    first = createNode(x);
    first->next = oldFirst;
    ++sz;
  }

 private:
  Node* first;
  size_type sz;
  static std::allocator<Node> alloc;

  Node* createNode(const_reference x) {
    Node* ret = alloc.allocate(1);
    alloc.construct(&ret->data, x);
    return ret;
  }

  template <typename ForwardIterator>
  void rangeInitialize(ForwardIterator beg, ForwardIterator ed) {
    Node* pre = nullptr;
    for (; beg != ed; ++beg) {
      Node* curr = createNode(*beg);
      if (sz == 0) {
        first = curr;
      } else {
        pre->next = curr;
      }
      pre = curr;
      ++sz;
    }
  }

  void destoryNode(Node* n) {
    alloc.destory(&n->data);
    alloc.deallocate(n, 1);
  }

  void clear() {
    while (first) {
      Node* tmp = first;
      first = first->next;
      destroyNode(tmp);
    }
  }
};

template <typename T>
std::allocator<typename SingleLinkedList<T>::Node> SingleLinkedList<T>::alloc;

}  // namespace algs4

#endif