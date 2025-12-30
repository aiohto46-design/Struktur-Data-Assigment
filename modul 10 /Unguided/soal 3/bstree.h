#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BSTree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);

public:
    BSTree();
    void insert(int value);

    void printPreOrder();
    void printInOrder();
    void printPostOrder();
};

#endif
