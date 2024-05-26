// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> tree;
  std::fstream input(filename);
  std::string word = "";
  char follow;
  while (input) {
    follow = input.get();
    if (isalpha(follow)) {
      follow = tolower(follow);
      word += follow;
    } else if (!(word.empty())) {
      tree.add(word);
      word = "";
    }
  }
  if (!(word.empty())) tree.add(word);
  input.close();
  return tree;
}
