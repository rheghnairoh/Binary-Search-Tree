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
  Node *insert(Node *, const int);     // insert recursive method
  void inorder(Node *);                // recursive inorder traversal helper
  Node *free(Node *);                  // delete a node, recursively helper
  Node *getItemNode(const int);        // get the node of an item
  Node *getPreviousNode(const int);    // get the previous node of an item
  int depth(Node *);                   // depth or height of tree helper
  void sortVectorItems();              // sorting items before balancing
  bool removeByMerging(Node *);        // remove item by merging helper
  Node *getMinNode(Node *);            // minimum node of the tree
  Node *removeRecursive(Node *, int);  // remove item recursive way
  void morrisInorder(Node *);          // morris inorder traversal helper
  int balanceFactor(Node *);           // balance factor of a node
  Node *rightRotation(Node *, Node *, Node *);
  Node *leftRotation(Node *, Node *, Node *);
  void createBackbone(); // create a backbone for DSW algorithm
  void makeRotations(int);  // make n left rotations till right is nullptr

 public:
  BinaryTree();
  void insertIterative(const int);  // insert item iteratively
  void insertRecursive(const int);  // insert item recursively
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
  int numberOfItems();
  void morrisInorderTraversal();
  void backboneTraversal();
  void balanceTreeDSW();
  ~BinaryTree();
};

#endif