#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_STACK = 20;

typedef int Item;

struct Stack {
    Item elemen[MAX_STACK];
    int idxTop;
};

void init(Stack &S);
bool empty(Stack S);
bool full(Stack S);

void pushData(Stack &S, Item x);
Item popData(Stack &S);

void tampil(Stack S);
void reverse(Stack &S);

// soal 2
void pushUrut(Stack &S, Item x);

// soal 3
void bacaInput(Stack &S);

#endif
