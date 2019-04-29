#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <vector>

struct node {
  int info;
  struct node *left, *right;
};
typedef struct node Node;

class BinaryTree {
  // private data members
  Node *root_;
  std::vector<int> data_;
  // private methods
  Node *makeTree(const int);           // make a node
  void setLeft(Node *, const int);     // set item to the left of given node
  void setRight(Node *, const int);    // set item to the right of given node
  Node *insert(Node *, const int);     // recursive method
  void inorder(Node *);                // recursive inorder traversal helper
  Node *free(Node *);                  // delete a node, recursively
  Node *getItemNode(const int);        // get the node of an item
  Node *getPreviousNode(const int);    // get the previous node of an item
  int depth(Node *);                   // depth or height of tree
  void sortVectorItems();              // sorting items before balancing
  bool removeByMerging(Node *);        // remove item by merging
  Node *getMinNode(Node *);            // minimum node of the tree
  Node *removeRecursive(Node *, int);  // remove item recursive way
  void morrisInorder(Node *);          // morris inorder traversal
  int balanceFactor(Node *);           // balance factor of a node
  Node *rightRotation(Node *, Node *, Node *);
  Node *leftRotation(Node *, Node *, Node *);

 public:
  BinaryTree();
  void insertIterative(const int);
  void insertRecursive(const int);
  void traverseRecursive();
  void traverseIterative();
  void insertRandomIterative(const int);
  void insertRandom(const int);
  // default M - delete by Merging = M, R for recursive deletion
  bool deleteItem(const int, const char = 'M');
  bool deleteRandom(const int, const char = 'M');
  void vectorInitialisation(std::vector<int>, int, int);
  void balanceTree();
  int height();
  void morrisInorderTraversal();
  void createBackbone();
  ~BinaryTree();
};

// implementation
// PRIVATE METHODS
Node *BinaryTree::makeTree(const int x) {
  Node *temp = new Node;
  temp->info = x;
  temp->left = temp->right = nullptr;
  return temp;
};
void BinaryTree::setLeft(Node *p, const int x) {
  if (p == nullptr)
    std::cout << ".....EMPTY NODE.....\n";
  else if (p->left != nullptr)
    std::cout << ".....NON-EMPTY LEFT NODE.....\n";
  else
    p->left = makeTree(x);
}
void BinaryTree::setRight(Node *p, const int x) {
  if (p == nullptr)
    std::cout << ".....EMPTY NODE.....\n";
  else if (p->right != nullptr)
    std::cout << ".....NON-EMPTY RIGHT NODE.....\n";
  else
    p->right = makeTree(x);
}
Node *BinaryTree::insert(Node *node, const int x) {
  if (node == nullptr)
    return makeTree(x);
  else if (x < node->info)
    node->left = insert(node->left, x);
  else if (x > node->info)
    node->right = insert(node->right, x);
  else {
    std::cout << x << " : is a duplicate therefore deprecated!\n";
    data_.pop_back();  // pop item from vector if it's duplicate
  }
  return node;
}
void BinaryTree::inorder(Node *p) {
  if (p == nullptr) return;
  inorder(p->left);
  std::cout << p->info << "    ";
  inorder(p->right);
}
Node *BinaryTree::free(Node *p) {
  if (p == nullptr) return nullptr;
  {
    free(p->left);
    free(p->right);
    delete p;
  }
  return nullptr;
}
Node *BinaryTree::getItemNode(const int x) {
  Node *p = root_;
  while (p != nullptr && p->info != x) {
    p = (p->info < x) ? p->right : p->left;
  }
  return p;
}
Node *BinaryTree::getPreviousNode(const int x) {
  Node *p = root_, *prev = nullptr;
  while (p != nullptr && p->info != x) {
    prev = p;
    p = (p->info < x) ? p->right : p->left;
  }
  return prev;
}
int BinaryTree::depth(Node *p) {
  if (p == nullptr) return 0;
  int left_depth = depth(p->left);
  int right_depth = depth(p->right);

  return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
}
void BinaryTree::sortVectorItems() { std::sort(data_.begin(), data_.end()); }
bool BinaryTree::removeByMerging(Node *p) {
  Node *node, *t, *prev;
  prev = getPreviousNode(p->info);
  node = p;
  if (p != nullptr) {
    if (node->right == nullptr) {
      t = node;
      node = node->left;
    } else if (p->left == nullptr) {
      t = node;
      node = node->right;
    } else {
      t = node->left;
      while (t->right != nullptr) t = t->right;
      t->right = node->right;
      t = node;
      node = node->left;
    }
    // Merging
    if (p == root_)
      root_ = node;
    else if (prev->left == p)
      prev->left = node;
    else
      prev->right = node;
    delete t;
    return true;
  }
  return false;
}
Node *BinaryTree::getMinNode(Node *p) {
  Node *node = p;
  if (root_ == nullptr) return nullptr;
  while (node->left != nullptr) node = node->left;
  return node;
}
Node *BinaryTree::removeRecursive(Node *p, const int x) {
  if (p == nullptr) return p;
  if (x < p->info)
    p->left = removeRecursive(p->left, x);
  else if (x > p->info)
    p->right = removeRecursive(p->right, x);
  else {
    if (p->left == nullptr) {
      Node *t = p->right;
      free(p);
      return t;
    } else if (p->right == nullptr) {
      Node *t = p->left;
      delete p;
      return t;
    }
    Node *t = getMinNode(p->right);
    p->info = t->info;
    p->right = removeRecursive(p->right, t->info);
  }
  return p;
}
void BinaryTree::morrisInorder(Node *root) {
  Node *p = root, *tmp;
  while (p != nullptr) {
    if (p->left == nullptr) {
      // std::cout << p->info << "    ";
      p = p->right;
    } else {
      tmp = p->left;
      while (tmp->right != nullptr && tmp->right != p) tmp = tmp->right;
      if (tmp->right == nullptr) {
        tmp->right = p;
        p = p->left;
      } else {
        // std::cout << p->info << "    ";
        tmp->right = nullptr;
        p = p->right;
      }
    }
  }
  std::cout << std::endl;
}
int BinaryTree::balanceFactor(Node *p) {
  return depth(p->left) - depth(p->right);
}
Node *BinaryTree::rightRotation(Node *grand_parent, Node *parent, Node *child) {
  if (parent != root_ && grand_parent != nullptr)
    grand_parent->right = child;
  else
    root_ = child;
  parent->left = child->right;
  child->right = parent;
  return grand_parent;
}
Node *BinaryTree::leftRotation(Node *grand_parent, Node *parent, Node *child) {
  if (parent != root_ && grand_parent != nullptr)
    grand_parent->right = child;
  else
    root_ = child;
  parent->right = child->left;
  child->left = parent;
  return grand_parent;
}

// PUBLIC METHODS
BinaryTree::BinaryTree() {
  root_ = nullptr;
  srand(time(NULL));
};
void BinaryTree::insertIterative(const int x) {
  Node *p, *q;
  if (root_ == nullptr)
    root_ = makeTree(x);
  else {
    p = q = root_;  // note p follows q
    while (x != p->info && q != nullptr) {
      p = q;
      if (x < p->info)
        q = p->left;
      else
        q = p->right;
    }
    if (x == p->info) {
      std::cout << x << " : is a duplicate therefore deprecated!\n";
      return;  // return immediately to avoid pushing data into vector
    } else if (x < p->info)
      setLeft(p, x);
    else
      setRight(p, x);
  }
  // store the items in vector for sorting, balancing and deletion purposes
  data_.push_back(x);
}
void BinaryTree::insertRecursive(const int x) {
  // store the items in vector for sorting, balancing and deletion purposes
  data_.push_back(x);
  root_ = insert(root_, x);
}
void BinaryTree::traverseRecursive() {
  inorder(root_);
  std::cout << std::endl;
}
void BinaryTree::traverseIterative() {
  Node *p = root_;
  std::stack<Node *> stack;
  while (p != nullptr) {
    while (p != nullptr) {
      if (p->right != nullptr) stack.push(p->right);
      stack.push(p);
      p = p->left;
    }
    p = stack.top();
    stack.pop();
    while (!stack.empty() && p->right == nullptr) {
      // std::cout << p->info << "    ";
      p = stack.top();
      stack.pop();
    }
    // std::cout << p->info << "    ";
    if (!stack.empty()) {
      p = stack.top();
      stack.pop();
    } else

      p = nullptr;
  }
}
void BinaryTree::insertRandomIterative(const int size) {
  for (int i = 0; i < size; ++i) insertIterative(rand());
}
void BinaryTree::insertRandom(const int size) {
  for (int i = 0; i < size; ++i) insertRecursive(rand());
}
bool BinaryTree::deleteItem(const int x, const char deleteType) {
  Node *node = getItemNode(x);
  // std::cout << "Attempting delete:   " << x << std::endl;
  if (root_ == nullptr)
    std::cout << "***EMPTY TREE***" << std::endl;
  else if (node != nullptr && node->info == x) {
    if (deleteType == 'R' || deleteType == 'r')
      removeRecursive(root_, x);
    else
      removeByMerging(node);  // default delete type is by merging
    return true;
  } else if (node == nullptr)
    std::cout << "Element: " << x << " is not in the tree!!" << std::endl;
}
bool BinaryTree::deleteRandom(const int number_of_items,
                              const char deleteType) {
  int index;
  if (number_of_items > data_.size()) return false;
  for (int i = 0; i < number_of_items; ++i) {
    index = rand() % data_.size();
    // std::cout << "Index: " << index << std::endl;
    // std::cout << "Size: " << data_.size() << std::endl;
    deleteItem(data_[index], deleteType);
    data_.erase(data_.begin() + index);
  }
  return true;
}
void BinaryTree::vectorInitialisation(std::vector<int> data, int start,
                                      int end) {
  int middle;
  if (start <= end) {
    middle = (start + end) / 2;
    root_ = insert(root_, data[middle]);
    vectorInitialisation(data, start, middle - 1);
    vectorInitialisation(data, middle + 1, end);
  }
}
void BinaryTree::balanceTree() {
  sortVectorItems();
  root_ = free(root_);
  vectorInitialisation(data_, 0, data_.size() - 1);
}
int BinaryTree::height() { return depth(root_); }
void BinaryTree::morrisInorderTraversal() { morrisInorder(root_); }
void BinaryTree::createBackbone() {
  Node *grand_parent = nullptr, *parent = root_, *child;
  while (parent != nullptr) {
    child = parent->left;
    if (child != nullptr) {
      grand_parent = rightRotation(grand_parent, parent, child);
      parent = child;
    } else {
      grand_parent = parent;
      parent = parent->right;
    }
  }
  // traversing
  Node *current = root_;
  while (current != nullptr) {
    // std::cout << current->info << "    ";
    current = current->right;
  }
  std::cout << std::endl;
}
BinaryTree::~BinaryTree() { root_ = free(root_); };

#endif