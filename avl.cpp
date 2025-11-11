#include "avl.h"

BST_AVL::BST_AVL() : root(nullptr) {}

BST_AVL::~BST_AVL() {
    destroy(root);
}

NodeBST* BST_AVL::addNode(NodeBST* node, const int& value) {
    if (!node) return new NodeBST(value);
    if (value < node->key) node->left = addNode(node->left, value);
    else if (value > node->key) node->right = addNode(node->right, value);
    return node;
}

void BST_AVL::insert(const int& key) {
    root = addNode(root, key);
}

int BST_AVL::getHeight(NodeBST* node) const {
    if (!node) return 0;
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);
    return 1 + (lh > rh ? lh : rh);
}

void BST_AVL::checkBalance(NodeBST* node, bool &balanced) const {
    if (!node) return;
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);
    if (abs(lh - rh) > 1) balanced = false;
    checkBalance(node->left, balanced);
    checkBalance(node->right, balanced);
}

bool BST_AVL::isBalanced() const {
    bool balanced = true;
    checkBalance(root, balanced);
    return balanced;
}

void BST_AVL::destroy(NodeBST* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void BST_AVL::printInOrder(NodeBST* node) const {
    if (!node) return;
    printInOrder(node->left);
    std::cout << node->key << " ";
    printInOrder(node->right);
}

NodeBST* BST_AVL::getRoot() const {
    return root;
}
