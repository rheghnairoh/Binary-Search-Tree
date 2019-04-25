#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "Tree.hpp"

int main(void) {
  clock_t start, end;
  BinaryTree tree_100, tree_1000, tree_10000;
  tree_100.insertRandom(100);
  tree_1000.insertRandom(1000);
  tree_10000.insertRandom(10000);

  std::cout << std::setprecision(9) << std::fixed;

  start = clock();
  tree_100.traverseRecursive();
  end = clock();
  std::cout << "Recursive Traversal - 100  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_100.traverseIterative();
  end = clock();
  std::cout << "Iterative Traversal - 100  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  tree_1000.traverseRecursive();
  end = clock();
  std::cout << "Recursive Traversal - 1000  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_1000.traverseIterative();
  end = clock();
  std::cout << "Iterative Traversal - 1000  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  tree_10000.traverseRecursive();
  end = clock();
  std::cout << "Recursive Traversal - 10000  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_10000.traverseIterative();
  end = clock();
  std::cout << "Iterative Traversal - 10000  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  return 0;
}
