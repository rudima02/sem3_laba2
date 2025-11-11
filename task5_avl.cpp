#include "avl.h"
#include <iostream>

void runTask5() {
    BST_AVL tree;
    int x;
    std::cout << "Введите последовательность: ";
    while (std::cin >> x && x != 0) {
        tree.insert(x);
    }

    if (tree.isBalanced()) std::cout << "YES\n";
    else std::cout << "NO\n";
}
 