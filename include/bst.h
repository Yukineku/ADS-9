// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
  struct Node {
    T value;
    Node *left;
    Node *right;
    int count;
    explicit Node(T v) {
      left = nullptr;
      right = nullptr;
      count = 1;
      value = v;
    }
  };
  Node *root;
  Node *addNode(Node *, const T &);
  int depthTree(Node *) const;
  int searchTree(Node *, const T &) const;

 public:
  BST() {
    root = nullptr;
  }
  void add(const T &);
  int depth() const;
  int search(const T &) const;
};
template<typename T>
typename BST<T>::Node *BST<T>::addNode(Node *node, const T &temp) {
  if (node == nullptr) {
    return new Node(temp);
  }
  if (node->value > temp) {
    node->left = addNode(node->left, temp);
  } else if (node->value < temp) {
    node->right = addNode(node->right, temp);
  } else {
    node->count = node->count + 1;
  }
  return node;
}
template<typename T>
void BST<T>::add(const T &temp) {
  root = addNode(root, temp);
}
template<typename T>
int BST<T>::depthTree(Node *node) const {
  if (node == nullptr) {
    return 0;
  }
  int left = depthTree(node->left);
  int right = depthTree(node->right);
  return std::max(left, right) + 1;
}
template<typename T>
int BST<T>::depth() const {
  return depthTree(root) - 1;
}
template<typename T>
int BST<T>::searchTree(Node *node, const T &temp) const {
  if (node == nullptr) {
    return 0;
  }
  if (node->value == temp) {
    return node->count;
  }
  if (node->value < temp) {
    return searchTree(node->right, temp);
  }
  return searchTree(node->left, temp);
}
template<typename T>
int BST<T>::search(const T &temp) const {
  return searchTree(root, temp);
}

#endif  // INCLUDE_BST_H_
