#include "Doublylist.h"

void createList(List &L) {
    L.First = NIL;
    L.Last = NIL;
}

address alokasi(infotype data) {
    address P = new Node;
    P->info = data;
    P->next = NIL;
    P->prev = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

void insertLast(List &L, address P) {
    if (L.First == NIL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;

    if (P == NIL) {
        cout << "List kosong" << endl;
    } else {
        while (P != NIL) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun Buat   : " << P->info.thnBuat << endl;
            cout << "------------------------" << endl;
            P = P->next;
        }
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NIL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NIL;
}

void deleteFirst(List &L) {
    address P;

    if (L.First != NIL) {
        P = L.First;

        if (L.First == L.Last) {
            L.First = NIL;
            L.Last = NIL;
        } else {
            L.First = P->next;
            L.First->prev = NIL;
            P->next = NIL;
        }
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    address P;

    if (L.Last != NIL) {
        P = L.Last;

        if (L.First == L.Last) {
            L.First = NIL;
            L.Last = NIL;
        } else {
            L.Last = P->prev;
            L.Last->next = NIL;
            P->prev = NIL;
        }
        dealokasi(P);
    }
}

void deleteAfter(List &L, address Prec) {
    address P;

    if (Prec != NIL && Prec->next != NIL) {
        P = Prec->next;

        if (P == L.Last) {
            L.Last = Prec;
            Prec->next = NIL;
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
        }

        P->next = NIL;
        P->prev = NIL;
        dealokasi(P);
    }
}
