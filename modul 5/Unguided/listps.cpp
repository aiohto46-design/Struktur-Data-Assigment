#include "listps.h"
using namespace std;

void createList(List &L) {
    L.first = Nil;
}

bool isEmpty(List L) {
    return L.first == Nil;
}

address alokasi(string tipe, int durasi, int harga) {
    address P = new Node;
    P->info.tipe = tipe;
    P->info.durasi = durasi;
    P->info.harga = harga;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Tipe PS: " << P->info.tipe << endl;
        cout << "Durasi: " << P->info.durasi << " jam" << endl;
        cout << "Harga per jam: Rp " << P->info.harga << endl;
        cout << "Total bayaran: Rp " << P->info.harga * P->info.durasi << endl;
        cout << endl;
        P = P->next;
    }
}

address findPS(List L, string tipe) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.tipe == tipe) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void updatePS(List &L, string tipeCari, int durasiBaru, int hargaBaru) {
    address P = findPS(L, tipeCari);
    if (P != Nil) {
        P->info.durasi = durasiBaru;
        P->info.harga = hargaBaru;
    }
}

int totalPendapatan(List L) {
    address P = L.first;
    int total = 0;
    while (P != Nil) {
        total += P->info.harga * P->info.durasi;
        P = P->next;
    }
    return total;
}