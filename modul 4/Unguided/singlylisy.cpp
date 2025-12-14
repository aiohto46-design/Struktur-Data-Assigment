//singlylist.cpp
#include "singlylist.h"

void CreateList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P-> info = x;
    P-> next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P-> next = L.first;
    L.first = P;
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        P-> next = Prec-> next;
        Prec-> next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q-> next != NULL) {
            Q = Q-> next;
        }
        Q-> next = P;
    }
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != NULL) {
            cout << P-> info << " ";
            P = P-> next;
        }
        cout << endl;
    }
}

void deleteFirst(List &L) {
     if (L.first != NULL) {
        address P = L.first;
        L.first = P->next;
           dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            dealokasi(L.first);
            L.first = NULL;
        } else {
            address P = L.first;
            address Prec = NULL;
            while (P->next != NULL) {
                Prec = P;
                P = P->next;
            }
            Prec->next = NULL;
            dealokasi(P);
        }
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
     while (L.first != NULL) {
         deleteFirst(L);
     }
}