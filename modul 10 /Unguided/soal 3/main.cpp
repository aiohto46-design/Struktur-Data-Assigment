#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    BSTree tree;

    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    tree.insert(2);
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);

    cout << "Pre-order traversal : ";
    tree.printPreOrder();

    cout << "In-order traversal  : ";
    tree.printInOrder();

    cout << "Post-order traversal: ";
    tree.printPostOrder();

    return 0;
}
