# <h1 align="center">Laporan Praktikum Modul 7 Stack </h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori
- Pengertian Stack

Stack adalah struktur data yang bekerja dengan dengan prinsip LIFO (Last in First Out), artinya elemen yang terakhir masuk akan menjadi yang pertama keluar. Dalam stack hanya ada satu pointer penting yaitu TOP yang menunjuk ke elemen paling atas, implementasi stack di modul ini menggunakan pointer seperti linked list, dengan node yang berisi info dan pointer next. Operasi utama pada stack adalah push untuk menambahkan elemen kebagian atas dan pop untuk mengambil sekaligus menghapus elemen paling atas. stack dianggap kosong jika TOP berniali NULL. Stack hanya bisa diakses dari bagian atas sehingga elemen dibawah nya tidak dapat diambil tanpa mengeluarkan elemen elemen di atas nya terlebih dahulu. 

## Guided

### 1. [Stack.h]

```C++
#ifndef STACK
#define STACK 
#define Nil nullptr

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);
#endif
```
File stack.h digunakan untuk mendefinisikan dan mengelola struktur data Stack. Stack merupakan struktur data dengan konsep LIFO (Last In, First Out), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Pada file ini terdapat deklarasi struktur data serta fungsi-fungsi yang mencakup pembuatan stack, pengecekan apakah stack kosong, penambahan data (push), penghapusan data (pop), pembaruan data (update), penampilan seluruh isi stack, serta pencarian data tertentu.

### 2. [Stack.cpp]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
Program ini merupakan penerapan struktur data Stack dengan metode penyimpanan berantai (seperti linked list). Stack dijalankan berdasarkan prinsip LIFO (Last In, First Out), yaitu elemen yang terakhir ditambahkan akan menjadi elemen pertama yang dikeluarkan.

### 3. [main.cpp]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    return 0;
}
```
Program utama ini digunakan untuk mengelola data pada sebuah Stack dengan menjalankan operasi push, pop, update, view, dan search. Program ini memperlihatkan perubahan isi stack setelah setiap operasi dilakukan.

## Unguided 
### 1. [soalstack.h]

```C++
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
```
### 2. [soalstack.cpp]
```C++
#include "Stack.h"

void init(Stack &S) {
    S.idxTop = -1;
}

bool empty(Stack S) {
    return S.idxTop == -1;
}

bool full(Stack S) {
    return S.idxTop == MAX_STACK - 1;
}

void pushData(Stack &S, Item x) {
    if (!full(S)) {
        S.idxTop++;
        S.elemen[S.idxTop] = x;
    }
}

Item popData(Stack &S) {
    if (!empty(S)) {
        Item hasil = S.elemen[S.idxTop];
        S.idxTop--;
        return hasil;
    }
    return -1;
}

void tampil(Stack S) {
    cout << "Isi Stack (atas ke bawah): ";
    for (int i = S.idxTop; i >= 0; i--) {
        cout << S.elemen[i] << " ";
    }
    cout << endl;
}

void reverse(Stack &S) {
    Stack bantu;
    init(bantu);

    while (!empty(S)) {
        pushData(bantu, popData(S));
    }

    S = bantu;
}

void pushUrut(Stack &S, Item x) {
    Stack sementara;
    init(sementara);

    while (!empty(S) && S.elemen[S.idxTop] < x) {
        pushData(sementara, popData(S));
    }

    pushData(S, x);

    while (!empty(sementara)) {
        pushData(S, popData(sementara));
    }
}

void bacaInput(Stack &S) {
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') break;

        if (ch >= '0' && ch <= '9') {
            pushData(S, ch - '0');
        }
    }
}
```
### 3. [main.cpp] soal 1

```C++
#include "Stack.h"

int main() {
    cout << "Hello world!" << endl;
    
    Stack S;
    init(S);

    pushData(S, 5);
    pushData(S, 1);
    pushData(S, 7);
    pushData(S, 3);

    tampil(S);

    cout << "Setelah dibalik:" << endl;
    reverse(S);
    tampil(S);

    return 0;
}
```
### 4. [main.cpp] soal 2

```C++
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    init(S);

    pushUrut(S, 4);
    pushUrut(S, 2);
    pushUrut(S, 9);
    pushUrut(S, 1);
    pushUrut(S, 6);

    tampil(S);

    cout << "Setelah dibalik:" << endl;
    reverse(S);
    tampil(S);

    return 0;
}
```
### 5. [main.cpp] soal 3

```C++
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    init(S);

    cout << "Masukkan angka (tanpa spasi): ";
    bacaInput(S);

    tampil(S);

    cout << "Setelah dibalik:" << endl;
    reverse(S);
    tampil(S);

    return 0;
}
```

#### Output:
#### Soal nomor 1:
<img width="537" height="120" alt="image" src="https://github.com/user-attachments/assets/954c58fc-bbe3-4b67-8572-2e4da2ad317f" />

#### Soal nomor 2:
<img width="437" height="93" alt="image" src="https://github.com/user-attachments/assets/f5ea83d8-7b70-4a1f-be05-144121690f48" />

#### Soal nomor 3:
<img width="567" height="139" alt="image" src="https://github.com/user-attachments/assets/c4288e94-4a7b-49c3-bf1c-e3c4169c326d" />

Program ini dirancang untuk menerapkan struktur data Stack dengan pendekatan berbasis pointer, serupa dengan konsep linked list. Mekanisme kerja stack mengikuti aturan LIFO (Last In First Out), di mana elemen yang paling akhir dimasukkan akan menjadi elemen pertama yang dikeluarkan.

#### Full code Screenshot:
<img width="389" height="598" alt="image" src="https://github.com/user-attachments/assets/3e512b65-2970-4421-b328-4bc036704737" />

<img width="349" height="651" alt="image" src="https://github.com/user-attachments/assets/cf508cd7-16a0-4d1a-b110-ba35dde746fd" />

<img width="481" height="551" alt="image" src="https://github.com/user-attachments/assets/1a96a355-d343-472e-8a1a-84c0d4702cee" />

<img width="455" height="553" alt="image" src="https://github.com/user-attachments/assets/d29923b4-c91c-4a67-9b98-bc8f1bf4bf7d" />

<img width="456" height="564" alt="image" src="https://github.com/user-attachments/assets/57ab9008-6c02-4c30-afd7-cb664ab099c7" />


## Kesimpulan

Ringkasan dan interpretasi dari hasil praktikum serta pembelajaran pada Modul 7 menunjukkan bahwa materi yang dibahas berfokus pada struktur data Stack. Stack merupakan struktur data yang bekerja dengan prinsip LIFO (Last In, First Out), di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Melalui praktikum ini, pemahaman terhadap konsep dan cara kerja stack menjadi lebih jelas karena dilakukan secara langsung melalui berbagai operasi. Latihan yang diberikan membantu memahami bagaimana stack digunakan untuk mengelola alur data masuk dan keluar secara teratur, serta bagaimana konsep LIFO dapat dimanfaatkan untuk menyelesaikan berbagai permasalahan.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
