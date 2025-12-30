#include "bstree.h"

BSTree::BSTree() {
    root = nullptr;
}

Node* BSTree::insert(Node* node, int value) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);

    return node;
}

void BSTree::insert(int value) {
    root = insert(root, value);
}

void BSTree::preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BSTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void BSTree::postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void BSTree::printPreOrder() {
    preOrder(root);
    cout << endl;
}

void BSTree::printInOrder() {
    inOrder(root);
    cout << endl;
}

void BSTree::printPostOrder() {
    postOrder(root);
    cout << endl;
}
