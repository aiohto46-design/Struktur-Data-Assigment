#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H


#include <string>

struct Product {
    std::string Nama;
    std::string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct SLLNode;
typedef SLLNode* address;

struct SLLNode {
    Product info;
    address next;
};

struct SLLList {
    address head;
};

// ADT SLL
bool isEmpty(const SLLList &L);
void createList(SLLList &L);
address allocate(const Product &P);
void deallocate(address p);

void insertFirst(SLLList &L, const Product &P);
void insertLast(SLLList &L, const Product &P);
void insertAfter(SLLList &L, address Q, const Product &P);

void deleteFirst(SLLList &L, Product &P);
void deleteLast(SLLList &L, Product &P);
void deleteAfter(SLLList &L, address Q, Product &P);

void updateAtPosition(SLLList &L, int posisi, const Product &P);
void viewList(const SLLList &L);
void searchByFinalPriceRange(const SLLList &L, float minPrice, float maxPrice);
void MaxHargaAkhir(const SLLList &L);

float HargaAkhir(const Product &p);

#endif