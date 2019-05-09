#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "Tree.hpp"

int main(void) {
  clock_t start, end;
  BinaryTree tree_100, tree_1000, tree_10000, tree_100000;
  tree_100.insertRandom(100);
  tree_1000.insertRandom(1000);
  tree_10000.insertRandom(10000);
  tree_100000.insertRandom(100000);

  std::cout << std::setprecision(6) << std::fixed;

  // COMPARISON FOR 100 NODES
  std::cout << "-------------------100 Nodes--------------------" << std::endl;
  std::cout << "Initial height            : " << tree_100.height() << std::endl;
  start = clock();
  tree_100.balanceTreeDSW();
  end = clock();
  std::cout << "Balanced Tree height      : " << tree_100.height() << std::endl;
  std::cout << "Time elapsed              : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  // COMPARISON FOR 1000 NODES
  std::cout << "-------------------1000 Nodes-------------------" << std::endl;
  std::cout << "Initial height            : " << tree_1000.height()
            << std::endl;
  start = clock();
  tree_1000.balanceTreeDSW();
  end = clock();
  std::cout << "Balanced Tree height      : " << tree_1000.height()
            << std::endl;
  std::cout << "Time elapsed              : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  // COMPARISON FOR 10, 000 NODES
  std::cout << "------------------10 000 Nodes-------------------" << std::endl;
  std::cout << "Initial height            : " << tree_10000.height()
            << std::endl;
  start = clock();
  tree_10000.balanceTreeDSW();
  end = clock();
  std::cout << "Balanced Tree height      : " << tree_10000.height()
            << std::endl;
  std::cout << "Time elapsed              : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  // COMPARISON FOR 100, 000 NODES
  std::cout << "-----------------100 000 Nodes------------------" << std::endl;
  std::cout << "Initial height            : " << tree_100000.height()
            << std::endl;
  start = clock();
  tree_100000.balanceTreeDSW();
  end = clock();
  std::cout << "Balanced Tree height      : " << tree_100000.height()
            << std::endl;
  std::cout << "Time elapsed              : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  return 0;
}


/*
1635696650 : is a duplicate therefore deprecated!
1107782853 : is a duplicate therefore deprecated!
-------------------100 Nodes--------------------
Initial height            : 14
Balanced Tree height      : 7
Time elapsed              : 0.000029
-------------------1000 Nodes-------------------
Initial height            : 22
Balanced Tree height      : 10
Time elapsed              : 0.000073
------------------10 000 Nodes-------------------
Initial height            : 29
Balanced Tree height      : 14
Time elapsed              : 0.000765
-----------------100 000 Nodes------------------
Initial height            : 39
Balanced Tree height      : 17
Time elapsed              : 0.023018

*/
