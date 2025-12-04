# <h1 align="center">Laporan Praktikum Modul 5 Singly Linked List (Bagian 2) </h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori
Operasi Searching

Searching adalah proses mencari node tertentu dalam list berdasarkan suatu kriteria (misalnya nama buah atau nilai tertentu)
Jika pointer next sudah NULL (ujung list) dan data belum ditemukan, maka data tidak ada di dalam list.
Jenis-jenis searching dalam program:
- FindNodeByData() → mencari node berdasarkan nama buah.
- FindNodeByAddress() → mencari node berdasarkan alamat memori.
- FindNodeByRange() → mencari node yang memiliki harga dalam rentang tertentu.
Dengan adanya fungsi searching ini, proses seperti insertAfter, deleteAfter, atau updateAfter dapat dilakukan dengan lebih mudah karena kita bisa menemukan node acuan (prev) terlebih dahulu.
## Guided 

### 1. [listbuah.h]

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};


bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &list);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedlist &List);
void updateLast(linkedlist &List);
void updateAfter(linkedlist &List, address prev);

// materi modul 5 (part 2, searching)
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif
```
Program ini dibuat untuk mengelola data buah menggunakan struktur data linked list. Dengan menggunakan struktur ini, data buah seperti nama, jumlah, dan harga dapat disimpan secara dinamis. Program ini memungkinkan pengguna untuk menambah, menghapus, atau memperbarui data di posisi mana pun dalam list. Selain itu, program juga menyediakan fitur pencarian berdasarkan nama, alamat node, maupun rentang harga, serta dapat menampilkan seluruh data buah yang tersimpan.

### 2. [listbuah.cpp]

```C++
#include "buah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == NULL){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = NULL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = NULL;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = NULL;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != NULL) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = NULL;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == NULL){
            List.first->next = NULL;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != NULL){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = NULL; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != NULL && nodePrev->next != NULL) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = NULL;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NULL) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != NULL) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != NULL){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = NULL; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NULL) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != NULL) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```
Program ini dirancang untuk mengelola data buah menggunakan struktur data linked list, sehingga data seperti nama, jumlah, dan harga dapat disimpan secara fleksibel. Dengan program ini, pengguna dapat menambah, menghapus, atau memperbarui data buah pada posisi mana pun dalam list. Selain itu, program juga menyediakan kemampuan untuk mencari data berdasarkan nama, alamat node, maupun rentang harga. Seluruh data buah yang tersimpan dapat ditampilkan secara lengkap melalui fitur yang disediakan.


### 3. [main.cpp]

```C++
#include "buah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Apel", 100, 20000);
    nodeB = alokasi("Cemangka", 75, 21000);
    nodeC = alokasi("Apple", 87, 20000);
    nodeD = alokasi("Tomato", 43, 21000);
    nodeE = alokasi("Duren", 70, 50000);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node: " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kalpa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 50, 1000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeA, nodeB);

     cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

     deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    return 0;
}

```
Program main() di atas adalah program utama untuk menguji semua fungsi linked list yang sudah kamu buat di file buah.cpp.

## Unguided 
untuk latihan soal saya menggunakan tema tempat pemancingan untuk mennetukkan harga ikan yang akan di jual
### 1. [Listikan.h]

```C++
//listikan.h
#ifndef LISTIKAN_H
#define LISTIKAN_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct ikan {
    string nama;
    float berat;
    int harga; 
};

typedef ikan infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
bool isEmpty(List L);
address alokasi(string nama, float berat, int harga);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findIkan(List L, string nama);
void updateIkan(List &L, string namaCari, float beratBaru, int hargaBaru);
int totalHarga(List L);

#endif
```

```C++
//listikan.cpp
#include "ListIkan.h"

void createList(List &L) {
    L.first = Nil;
}

bool isEmpty(List L) {
    return (L.first == Nil);
}

address alokasi(string nama, float berat, int harga) {
    address P = new Node;
    P->info.nama = nama;
    P->info.berat = berat;
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
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Nama ikan : " << P->info.nama << endl;
            cout << "Berat (kg): " << P->info.berat << endl;
            cout << "Harga/kg  : " << P->info.harga << endl;
            cout << "---------------------------" << endl;
            P = P->next;
        }
    }
}

address findIkan(List L, string nama) {
    address P = L.first;
    while (P != Nil && P->info.nama != nama) {
        P = P->next;
    }
    return P;
}

void updateIkan(List &L, string namaCari, float beratBaru, int hargaBaru) {
    address P = findIkan(L, namaCari);
    if (P != Nil) {
        P->info.berat = beratBaru;
        P->info.harga = hargaBaru;
        cout << "Data ikan " << namaCari << " berhasil diperbarui!" << endl;
    } else {
        cout << "Ikan " << namaCari << " tidak ditemukan dalam list." << endl;
    }
}

int totalHarga(List L) {
    address P = L.first;
    int total = 0;
    while (P != Nil) {
        total += (P->info.berat * P->info.harga);
        P = P->next;
    }
    return total;
}
```

```C++
//main.cpp
#include "ListIkan.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi("Lele", 2.5, 20000));
    insertLast(L, alokasi("Gurame", 1.2, 35000));
    insertLast(L, alokasi("Patin", 3.0, 25000));
    insertLast(L, alokasi("Nila", 2.0, 30000));

    cout << "=== Data Ikan Hasil Pancingan ===" << endl;
    printInfo(L);

    cout << "\nCari ikan 'Patin':" << endl;
    address cari = findIkan(L, "Patin");
    if (cari != Nil)
        cout << "Ikan ditemukan! Berat: " << cari->info.berat << " kg, Harga/kg: " << cari->info.harga << endl;
    else
        cout << "Ikan tidak ditemukan." << endl;

    cout << "\nUpdate ikan 'Lele' jadi berat 3 kg dan harga 22000/kg" << endl;
    updateIkan(L, "Lele", 3.0, 22000);

    cout << "\n=== Data Setelah Update ===" << endl;
    printInfo(L);

    int total = totalHarga(L);
    cout << "\nTotal harga semua ikan: Rp " << total << endl;

    return 0;
}
```

#### Output:
<img width="1051" height="816" alt="image" src="https://github.com/user-attachments/assets/c9f2967d-be30-4eec-a27b-3b7a801f3814" />

program ini digunakan untuk mengelola data hasil pemancingan menggunakan struktur data singly linked list, didalam program, setiap node mewakili seekor ikan yang terdiri dari nama ikan, berat dan harganya, dengan linked list, program bisa menambahkan di list tertentu, menghapus data ikan, mengupdate data ikan, mencari data ikan berdasarkan nama, alamat dan rata rata harga, menampilkan semua data ikan dan bisa menghitung jumlah data.

#### Full code Screenshot:
<img width="1916" height="993" alt="image" src="https://github.com/user-attachments/assets/2549e94c-b321-4029-b69a-3b742d129a6c" />




## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. Pada modul ini dipelajari cara membuat, menambah, menghapus, menampilkan dan mencari node dalam linked list menggunakan pointer berdasarkan nama, alamat dan harga.
Secara keseluruhan, program pemancingan ini membantu mempelajari manajemen memori dinamis, pointer, dan struktur data linked list, dalam tema pemancingan, sama seperti materi pada modul sebelumnya hanya saja pada program kali ini ada tambahan program baru yaitu serching untuk mencari data ikan sesuai nama, alamat node dan rata rata harga.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
