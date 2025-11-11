#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

struct NodeBST {
    int key;
    NodeBST* left;
    NodeBST* right;

    NodeBST(const int& k) : key(k), left(nullptr), right(nullptr) {}
};

class BST_AVL {
private:
    NodeBST* root;

    NodeBST* addNode(NodeBST* node, const int& value);
    int getHeight(NodeBST* node) const;
    void checkBalance(NodeBST* node, bool &balanced) const;
    void destroy(NodeBST* node);

public:
    BST_AVL();
    ~BST_AVL();

    void insert(const int& key);
    bool isBalanced() const;

    void printInOrder(NodeBST* node) const;
    NodeBST* getRoot() const;
};
