#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "Tree.hpp"

int main(void) {
  clock_t start, end;
  BinaryTree tree_1000, tree_10000, tree_100000, tree_500000;
  tree_1000.insertRandom(1000);
  tree_10000.insertRandom(10000);
  tree_100000.insertRandom(100000);
  tree_500000.insertRandom(500000);

  std::cout << std::setprecision(9) << std::fixed;
  // COMPARISON FOR 1,000 NODES
  start = clock();
  tree_1000.morrisInorderTraversal();
  end = clock();
  std::cout << "-------------------1 000 Nodes--------------------"<<std::endl;
  std::cout << "Morris Alg Traversal - 1000      : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_1000.createBackbone();
  end = clock();
  std::cout << "DSW-Backbone Traversal - 1000    : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  // COMPARISON FOR 10,000 NODES
  start = clock();
  tree_10000.morrisInorderTraversal();
  end = clock();
  std::cout << "-------------------10 000 Nodes-------------------"<<std::endl;
  std::cout << "Morris Alg Traversal - 10000     : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_10000.createBackbone();
  end = clock();
  std::cout << "DSW-Backbone Traversal - 10000   : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  // COMPARISON FOR 100,000 NODES
  start = clock();
  tree_100000.morrisInorderTraversal();
  end = clock();
  std::cout << "------------------100 000 Nodes-------------------"<<std::endl;
  std::cout << "Morris Alg Traversal - 100000    : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_100000.createBackbone();
  end = clock();
  std::cout << "DSW-Backbone Traversal - 100000  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  // COMPARISON FOR 500,000 NODES
  start = clock();
  tree_500000.morrisInorderTraversal();
  end = clock();
  std::cout << "------------------500 000 Nodes-------------------"<<std::endl;
  std::cout << "Morris Alg Traversal - 500000    : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;
  start = clock();
  tree_500000.createBackbone();
  end = clock();
  std::cout << "DSW-Backbone Traversal - 500000  : "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  return 0;
}


/*


-------------------1 000 Nodes--------------------
Morris Alg Traversal - 1000      : 0.003666000

DSW-Backbone Traversal - 1000    : 0.002505000

-------------------10 000 Nodes-------------------
Morris Alg Traversal - 10000     : 0.004414000

DSW-Backbone Traversal - 10000   : 0.003795000

------------------100 000 Nodes-------------------
Morris Alg Traversal - 100000    : 0.025775000

DSW-Backbone Traversal - 100000  : 0.042998000

------------------500 000 Nodes-------------------
Morris Alg Traversal - 500000    : 0.111209000

DSW-Backbone Traversal - 500000  : 0.199364000


*/