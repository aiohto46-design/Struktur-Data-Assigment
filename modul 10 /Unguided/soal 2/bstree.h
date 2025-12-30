#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
};

typedef Node* address;

address createNode(int x);
void insertNode(address &root, int x);
void inOrder(address root);

int hitungJumlahNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root);

#endif
