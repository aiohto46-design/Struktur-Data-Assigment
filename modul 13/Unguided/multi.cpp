#include "multi.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype data) {
    address P = new ElmList;
    P->info = data;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        address firstNode = L.first;
        if (firstNode->next == firstNode) {
            P = firstNode;
            L.first = NULL;
        } else {
            address last = L.first;
            while (last->next != L.first) {
                last = last->next;
            }
            P = L.first;
            L.first = P->next;
            last->next = L.first;
        }
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != NULL) {
        address curr = L.first;
        address prev = NULL;
        if (curr->next == curr) {
            P = curr;
            L.first = NULL;
        } else {
            while (curr->next != L.first) {
                prev = curr;
                curr = curr->next;
            }
            P = curr;
            prev->next = L.first;
        }
        P->next = NULL;
    }
}

address findElm(List L, infotype x) {
    if (L.first == NULL) return NULL;

    address P = L.first;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printInfo(List L) {
    if (L.first != NULL) {
        address P = L.first;
        do {
            cout << "Nama : " << P->info.nama << endl;
            cout << "NIM  : " << P->info.nim << endl;
            cout << "L/P  : " << P->info.jk << endl;
            cout << "IPK  : " << P->info.ipk << endl;
            cout << endl;
            P = P->next;
        } while (P != L.first);
    }
}
