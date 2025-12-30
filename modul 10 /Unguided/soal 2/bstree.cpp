#include "bstree.h"

address createNode(int x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, int x) {
    if (root == NULL) {
        root = createNode(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL)
        return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotal(address root) {
    if (root == NULL)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root) {
    if (root == NULL)
        return 0;

    int kiri = hitungKedalaman(root->left);
    int kanan = hitungKedalaman(root->right);

    return (kiri > kanan ? kiri : kanan) + 1;
}
