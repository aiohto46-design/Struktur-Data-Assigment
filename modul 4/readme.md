# <h1 align="center">Laporan Praktikum Modul 4 Singly Linked List </h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori

Singly Linked List (biasa di sebut list) adalah salah satu bentuk struktur data (representasi peyimpanan) yang terdiri dari serangkaian elemen data yang saling terhubung (berkaitan) dan bersifat fleksibel, karena ukurannya bisa bertambah atau berkurang sesuai kebutuhan. setiap elemen dalam linked list disebut node, yang berisi data atau pointer yang menunjuk ke node berikutnya.

Linked list digunakkan untuk menyimpan data baik yang bersifat tunggal (satu variable) atau majemuk (beberapa variable).
Implementasi Linked List

Linked list dapat dibuat menggunakan Array atau Pointer, namun pointer lebih sering digunakan karena beberapa alasan:
1. Array bersifat statis, sedangkan pointer bersifat dinamis.
2. Bentuk data pada linked list saling berhubungan, sehingga mudah diatur dengan pointer.
3. Sifatnya yang fleksibel lebih cocok dengan pointer yang dapat menyesuaikan kebutuhan memori.
4. Array lebih sulit digunakan untuk linked list, sedangkan pointer lebih mudah.
5. Array cocok untuk data dengan jumlah elemen tetap, sedangkan linked list untuk data yang jumlahnya berubah-ubah.

## Guided 

### 1. [list.h]

```C++
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

```
program digunakan untuk membuat struct mahasiswa yang terdiri dari char nim dan nilai1, nilai2.
### 2. [list.cpp]

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == NIL){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = NIL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = NIL;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = NIL;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != NIL) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NIL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NIL) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
program ini digunakan untuk mendeklarasikan semu fungsi yang di butuhkan untuk membuat program berjalan.

### 3. [main.cpp]

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    datamahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

```
program ini merupakan file utama untuk menjalankan dan menyatukan semua program yang sudah di buat di atas.


## Unguided 

### 1. [Single List]

```C++
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
```
Berisi deklarasi struktur data dan prototype fungsi, seperti ElmtList, List, serta fungsi CreateList, insert, delete, nbList, dan lainnya.
Fungsinya sebagai kerangka utama dari program agar bisa dipanggil di file lain.

```C++
//singlylist.cpp
#include "singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.first = NULL;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new Elmlist;
    P-> info = x;
    P-> next = NULL;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Insert di awal
void insertFirst(List &L, address P) {
    P-> next = L.first;
    L.first = P;
}

// Insert setelah node tertentu
void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        P-> next = Prec-> next;
        Prec-> next = P;
    }
}

// Insert di akhir
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

// Print isi list
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

// Hapus node pertama
void deleteFirst(List &L) {
     if (L.first != NULL) {
        address P = L.first;
        L.first = P->next;
           dealokasi(P);
    }
}

// // Hapus node terakhir
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

// Hapus setelah node tertentu
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


// func untuk menghapus list
void deleteList(List &L) {
     while (L.first != NULL) {
         deleteFirst(L);
     }
}
```
berisi semua implementasi mulai dari pembuatan list, alokasi node, operasi insert & delete, sampai menghitung jumlah node (nbList) dan menghapus semua node (deleteList).

```C++
//main.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);

    // Alokasi node
    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi Linked List Awal: ";
    printInfo(L);

    // Hapus node 9 (deleteFirst)
    deleteFirst(L);
    // Hapus node 2 (deleteLast)
    deleteLast(L);
    // Hapus node 8 (deleteAfter)
    address Prec = L.first->next; // node setelah 12 (yaitu 8)
    deleteAfter(L, Prec);

    cout << "Isi Linked List Setelah Delete: ";
    printInfo(L);

    cout << "Jumlah node: " << nbList(L) << endl;

    // Hapus semua node
    deleteList(L);
    cout << "List setelah deleteList(): ";
    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}
```
Program menambahkan beberapa data ke list, menampilkan isi list, lalu melakukan operasi penghapusan dan menampilkan hasil akhirnya.

#### Output:
<img width="992" height="245" alt="image" src="https://github.com/user-attachments/assets/f08a2feb-9c01-499e-af45-5b8c13d8defe" />


Program ini digunakan untuk mengelola data secara dinamis menggunakan struktur Single Linked List, di mana data dapat ditambahkan, dihapus, dan ditampilkan dengan memanfaatkan konsep pointer pada bahasa C++.

#### Full code Screenshot:
<img width="1915" height="1029" alt="image" src="https://github.com/user-attachments/assets/86a1b4a7-bdf9-4fa4-a8e4-8c10a3e0c5e5" />



## Kesimpulan
Pada praktikum ini, kita mempelajari bagaimana membangun dan mengelola struktur linked list menggunakan pointer. Mulai dari membuat node, menambahkan node di awal atau akhir list, menghapus node, hingga menampilkan seluruh isi list. Kita juga mengenal fungsi-fungsi penting seperti insertFirst, insertLast, deleteFirst, deleteLast, dan nbList. Secara keseluruhan, modul ini membantu kita memahami cara mengatur memori serta bagaimana data saling terhubung secara dinamis dalam sebuah list.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
