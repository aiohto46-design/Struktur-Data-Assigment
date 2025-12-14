#ifndef LISTPS_H
#define LISTPS_H
#define Nil NULL

#include <iostream>
using namespace std;

struct ps {
    string tipe;
    int durasi;
    int harga;
};

typedef ps infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
bool isEmpty(List L);
address alokasi(string tipe, int durasi, int harga);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findPS(List L, string tipe);
void updatePS(List &L, string tipeCari, int durasiBaru, int hargaBaru);
int totalPendapatan(List L);

#endif