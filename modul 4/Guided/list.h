#ifndef LIST_H
#define LIST_H
#define NIL NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa datamahasiswa;

typedef struct node *address;

struct node{
    datamahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodebaru);
void insertAfter(linkedlist &list, address nodebaru, address prev);
void insertLast(linkedlist &list, address nodebaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodeprev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

#endif
