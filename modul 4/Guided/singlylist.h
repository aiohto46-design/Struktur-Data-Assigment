//singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define NIL NUL 

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist{ 
    infotype info;
    address next;
};

struct List{
    address first;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void printInfo(List L);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif