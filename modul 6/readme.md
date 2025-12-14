# <h1 align="center">Laporan Praktikum Modul 6 Double Linked List (Bagian Pertama) </h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori
Double Linked List

Doubly Linked list adalah linked list yang masing – masing elemen nya memiliki 2 successor, yaitu
successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen
sesudahnya (next).

Doubly linked list juga menggunakan dua buah successor utama yang terdapat pada list, yaitu first
(successor yang menunjuk elemen pertama) dan last (susesor yang menunjuk elemen terakhir list).
Komponen-komponen dalam Doubly linked list:
1. First : pointer pada list yang menunjuk pada elemen pertama list.
2. Last : pointer pada list yang menunjuk pada elemen terakhir list.
3. Next : pointer pada elemen sebagai successor yang menunjuk pada elemen didepannya.
4. Prev : pointer pada elemen sebagai successor yang menunjuk pada elemen dibelakangnya.


## Guided 

### 1. [DLLPlayList.h]

```C++
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;    
};

typedef struct Node* address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address Q);

void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

float getPopularityScore(Song S);

#endif
```
Program ini adalah penerapan Doubly Linked List untuk mengelola data playlist lagu, di mana setiap node berisi informasi lagu dan saling terhubung ke node sebelumnya dan sesudahnya. Program ini menyediakan fitur untuk menambahkan, menghapus, memperbarui, menampilkan, serta mencari lagu berdasarkan tingkat popularitas.

### 2. [DLLPlayList.cpp]

```C++
#include "DLLPlaylist.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void deallocate(address P) {
    delete P;
}

float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q != nullptr) {
        address P = allocate(S);
        P->next = Q->next;
        P->prev = Q;

        if (Q->next != nullptr)
            Q->next->prev = P;
        else
            L.tail = P;

        Q->next = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q != nullptr) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;

            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.head;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.head = P->next;
            L.head->prev = nullptr;
        }
        deallocate(P);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.tail;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.tail = P->prev;
            L.tail->next = nullptr;
        }
        deallocate(P);
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->next != nullptr) {
        address P = Q->next;
        S = P->info;

        Q->next = P->next;
        if (P->next != nullptr)
            P->next->prev = Q;
        else
            L.tail = Q;

        deallocate(P);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;
        S = P->info;

        if (P == L.head) {
            deleteFirst(L, S);
        } else {
            P->prev->next = Q;
            Q->prev = P->prev;
            deallocate(P);
        }
    }
}

void updateAtPosition(List &L, int posisi) {
    int idx = 1;
    address P = L.head;

    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != nullptr) {
        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void updateBefore(List &L, address Q) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;

        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int idx = 1;

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        cout << idx << ". "
             << P->info.Title << " | " << P->info.Artist
             << " | " << P->info.DurationSec << "s | PC: "
             << P->info.PlayCount << " | Rating: "
             << P->info.Rating << " | PopularityScore: "
             << pop << endl;

        P = P->next;
        idx++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address P = L.head;
    int idx = 1;

    cout << "\nHasil searching PopularityScore in [" 
         << minScore << ", " << maxScore << "]\n";

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        if (pop >= minScore && pop <= maxScore) {
            cout << idx << ". " << P->info.Title 
                 << " | PopularityScore: " << pop << endl;
        }

        P = P->next;
        idx++;
    }
}
```
Program ini merupakan penerapan Doubly Linked List secara menyeluruh untuk mengelola playlist lagu. Implementasinya mencakup proses alokasi dan dealokasi node, operasi penyisipan dan penghapusan pada berbagai posisi, pembaruan data lagu, perhitungan skor popularitas, pencarian data berdasarkan rentang skor, serta penampilan seluruh isi playlist secara terurut. Setiap lagu direpresentasikan sebagai node yang saling terhubung dua arah, sehingga memungkinkan pengelolaan dan manipulasi data playlist secara lebih mudah dan fleksibel.

### 3. [main.cpp]

```C++
#include "DLLPlaylist.h"

address getNodeAt(List L, int posisi) {
    int idx = 1;
    address P = L.head;
    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }
    return P;
}

int main() {
    List L;
    createList(L);

    insertLast(L, {"Senja di Kota", "Nona Band", 210, 150, 4.2});
    insertLast(L, {"Langkahmu", "Delta", 185, 320, 4.8});
    insertLast(L, {"Hujan Minggu", "Arka", 240, 90, 3.95});

    cout << "\n=== List Awal ===\n";
    viewList(L);

    Song removed;
    deleteLast(L, removed);

    cout << "\n Setelah deleteLast \n";
    viewList(L);

    cout << "\n Update posisi ke-2 \n";
    updateAtPosition(L, 2);

    cout << "\n Setelah Update \n";
    viewList(L);

    address pos2 = getNodeAt(L, 2);

    insertBefore(L, pos2, {"Senandung", "Mira", 175, 120, 4.0});
    cout << "\n Setelah insertBefore posisi 2 \n";
    viewList(L);

    cout << "\n UpdateBefore posisi 2 \n";
    pos2 = getNodeAt(L, 2);
    updateBefore(L, pos2);

    cout << "\n Setelah updateBefore \n";
    viewList(L);

    cout << "\n deleteBefore posisi 3 \n";
    Song removed2;
    address pos3 = getNodeAt(L, 3);
    deleteBefore(L, pos3, removed2);

    cout << "\n Setelah deleteBefore \n";
    viewList(L);

    cout << "\n Searching PopularityScore 150–300 \n";
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}
```
Program ini berfungsi untuk mengelola data playlist lagu, mulai dari menambah, menghapus, menyisipkan, hingga memperbarui lagu pada posisi tertentu. Seluruh proses pengelolaan playlist menggunakan struktur data Doubly Linked List, sehingga setiap lagu direpresentasikan sebagai node yang saling terhubung dua arah dan dapat diakses, dipindahkan, serta dimodifikasi dengan lebih mudah.

## Unguided 
### 1. [doublelist.h]

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define NIL NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void createList(List &L);
address alokasi(infotype data);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

address findElm(List L, string nopol);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);

#endif
```
### 2. [doublelist.cpp]
```C++
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
```
### 3. [main.cpp]

```C++
#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P;

    createList(L);

    x.nopol = "D001";
    x.warna = "hitam";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    x.nopol = "D003";
    x.warna = "putih";
    x.thnBuat = 70;
    insertLast(L, alokasi(x));

    x.nopol = "D004";
    x.warna = "kuning";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    cout << "DATA LIST KENDARAAN" << endl;
    cout << "==================" << endl;
    printInfo(L);

    cout << "\nMencari nomor polisi D001" << endl;
    P = findElm(L, "D001");
    if (P != NIL) {
        cout << "Data ditemukan:" << endl;
        cout << "Nopol : " << P->info.nopol << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    cout << "\nHapus elemen pertama" << endl;
    deleteFirst(L);
    printInfo(L);

    cout << "\nHapus elemen terakhir" << endl;
    deleteLast(L);
    printInfo(L);

    return 0;
}
```

#### Output:
<img width="486" height="714" alt="image" src="https://github.com/user-attachments/assets/5b97cf0c-4982-45c3-9f08-0d1eb94ecdc0" />



Program ini dibuat untuk mengelola data kendaraan menggunakan Doubly Linked List.
Setiap node menyimpan nomor polisi, warna kendaraan, dan tahun pembuatan.
Program dapat melakukan:
- menambah data kendaraan ke belakang list (insertLast)
- menampilkan seluruh data (printInfo)
- mengecek apakah nopol sudah terdaftar (findElm)
- mencari data kendaraan tertentu
- menghapus data berdasarkan posisi (deleteFirst, deleteLast, deleteAfter)
- menolak input kendaraan dengan nopol yang sama (duplikasi)
Program ini mensimulasikan cara kerja struktur data Double Linked List untuk pengolahan data kendaraan secara dinamis.
#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/cb3d1f32-c50b-487f-b408-ae51c39b75b6" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/362d23f7-1a6d-48df-851b-5f8361dffdda" />

<img width="1917" height="1079" alt="image" src="https://github.com/user-attachments/assets/cae371a4-c2bb-432e-a55a-fcb7a56fb7ca" />


## Kesimpulan
Dari hasil praktikum dan pembelajaran di modul ini, bisa disimpulkan kalau Doubly Linked List cocok banget buat ngelola data yang sifatnya dinamis. Soalnya, tiap node punya pointer ke depan dan ke belakang, jadi proses nyari, nambah, atau hapus data jadi lebih gampang tanpa harus mindahin semua elemen. Dibanding Single Linked List, struktur ini lebih fleksibel, terutama pas ngelakuin insert dan delete di bagian tengah list.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
