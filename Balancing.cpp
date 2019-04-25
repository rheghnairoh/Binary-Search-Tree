#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "Tree.hpp"

int main(void) {
  BinaryTree bst;
  for (int i = 0; i < 100; ++i) {
    bst.insertRandom(20);
    bst.deleteRandom(4);
  }
  std::cout << "         TREE 1       " << std::endl;
  std::cout << "Unbalanced Tree height:       " << bst.height() << std::endl;
  bst.balanceTree();
  std::cout << "Balanced Tree height:       " << bst.height() << std::endl;

  BinaryTree bst2;
  for (int i = 0; i < 100; ++i) {
    bst2.insertRandom(45);
    bst2.deleteRandom(7);
  }
  std::cout << "         TREE 2       " << std::endl;
  std::cout << "Unbalanced Tree height:       " << bst2.height() << std::endl;
  bst2.balanceTree();
  std::cout << "Balanced Tree height:       " << bst2.height() << std::endl;
  return 0;
}