# <h1 align="center">Laporan Praktikum Modul 8 Queue </h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori
#### Queue

Queue merupakan struktur data yang dapat diartikan seperti sebuah antrean.
Misalkan antrean pada loket pembelian tiket Kereta Api. Orang yang akan mendapatkan pelayanan
yang pertama adalah orang pertamakali masuk dalam antrean tersebut dan yang terakhir masuk dia
akan mendapatkan layanan yang terakhir pula. Jadi prinsip dasar dalam Queue adalah FIFO (First in
Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian
struktur Queue dalam C dapat menggunakan tipe data array dan linked list.

#### 1. Operasi Dasar pada Queue
- Enqueue → menambahkan elemen ke dalam antrean (di bagian belakang / tail)
- Dequeue → menghapus elemen dari antrean (di bagian depan / head)
- Front / Peek → melihat elemen paling depan tanpa menghapusnya
- IsEmpty → mengecek apakah queue kosong
- IsFull (hanya pada implementasi berbasis array)

## Guided 

### 1. [Queu.h]

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);

int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
```
Program ini dirancang untuk mengatur antrean pengiriman paket ekspedisi dengan memanfaatkan struktur data Queue. Program menyediakan fungsi untuk menambahkan paket ke dalam antrean, mengeluarkan paket dari antrean, menampilkan daftar paket yang menunggu, serta menghitung keseluruhan biaya pengiriman.

### 2. [Queu.cpp]

```C++
#include "queu.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    Paket P;
    cout << "Masukkan Kode Resi     : "; cin >> P.KodeResi;
    cout << "Masukkan Nama Pengirim : "; cin >> P.NamaPengirim;
    cout << "Masukkan Berat Barang  : "; cin >> P.BeratBarang;
    cout << "Masukkan Tujuan        : "; cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Menghapus paket dengan resi: " << Q.dataPaket[Q.Head].KodeResi << "\n";

    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.Tail--;

    if (Q.Tail < 0) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "\n--- Daftar Paket dalam Antrian ---\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Posisi " << i + 1 << ":\n";
        cout << "  Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
        cout << "  Pengirim      : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "  Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << "  Tujuan        : " << Q.dataPaket[i].Tujuan << endl;
        cout << "-----------------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}
```
Program ini dibuat untuk mengelola antrean paket ekspedisi dengan menggunakan struktur data Queue berbasis array. Di dalam program terdapat proses penambahan paket (enqueue), pengeluaran paket (dequeue), penampilan isi antrean, serta perhitungan total biaya pengiriman yang didasarkan pada berat barang. Secara keseluruhan, program ini mensimulasikan mekanisme antrean yang diterapkan pada layanan pengiriman paket.

### 3. [main.cpp]

```C++
#include <iostream>
#include "queu.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "\n--- Gojira Express ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "5. Exit\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            enQueue(Q);
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman: Rp. " 
                 << TotalBiayaPengiriman(Q) << endl;
            break;

        case 5:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
```
Program main() ini berperan sebagai menu interaktif untuk mengoperasikan sistem antrean ekspedisi Gojira Express. Melalui menu yang disediakan, pengguna dapat menambahkan data paket ke dalam antrean (enqueue), menghapus paket yang berada di posisi terdepan (dequeue), menampilkan seluruh data paket dalam antrean, menghitung total biaya pengiriman, serta mengakhiri program. Secara keseluruhan, program ini mensimulasikan mekanisme antrean pada layanan pengiriman paket dengan memanfaatkan struktur data Queue.

## Unguided 
### 1. [queue.h]

```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q, infotype &x);
void printInfo(Queue Q);

#endif
```
### 2. [queue.cpp]

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail < Q.head;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q, infotype &x) {
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    
    if (Q.tail < Q.head) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
### 4. [queue2.cpp]

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q, infotype &x) {
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head++;  
        }
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
### 5. [queue3.cpp]

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return (Q.tail + 1) % MAX == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q, infotype &x) {
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX;
        }
    }
    cout << endl;
}
```
### 3. [main.cpp]

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    infotype x;

    cout << "Hello world!" << endl;
    cout << "---" << endl;
    cout << "H - T    Queue Info" << endl;
    cout << "---" << endl;
    
    CreateQueue(Q);
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q, x); printInfo(Q);
    dequeue(Q, x); printInfo(Q);
    dequeue(Q, x); printInfo(Q);

    return 0;
}
```

#### Output:
#### Soal 1:
<img width="420" height="215" alt="image" src="https://github.com/user-attachments/assets/6e0270ae-d186-480b-b314-2aa2e627c44a" />

#### Soal 2:
<img width="420" height="212" alt="image" src="https://github.com/user-attachments/assets/1176096f-9f93-4c99-a7a5-ba09a65d04de" />

#### Soal 3:
<img width="422" height="210" alt="image" src="https://github.com/user-attachments/assets/5ce8f549-5db3-429a-81fc-1f9ccb29af05" />


Program ini dirancang untuk menerapkan konsep ADT Queue (antrian) menggunakan array dalam bahasa C++. Program tersebut mensimulasikan proses antrean melalui operasi utama enqueue (penambahan data) dan dequeue (penghapusan data) sesuai dengan prinsip FIFO (First In First Out). Pada latihan ini, struktur queue diimplementasikan dengan beberapa pendekatan, yaitu queue dengan pergerakan head dan tail serta circular queue, guna memperlihatkan perbedaan cara pengelolaan indeks dalam struktur data queue.

#### Full code Screenshot:
<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/bd22c769-31e9-4f99-85ed-96f350694ea0" />

<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/b6f2b890-865a-47c6-9d7b-9d87d1e5225a" />

<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/07ee1769-749d-4466-be52-b8fa446ffb28" />

<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/50515a15-c9d8-4abf-8645-c12b5d3b96dd" />

<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/14bdb1d7-f7d9-45a6-86e8-5f3388ade9c5" />


## Kesimpulan
Ringkasan dan interpretasi dari hasil praktikum serta pembelajaran pada modul ini menunjukkan bahwa struktur data Queue sangat efektif digunakan untuk menangani proses antrean yang berjalan secara berurutan. Penerapan circular queue terbukti lebih efisien dibandingkan queue linear karena mampu memanfaatkan ruang memori secara optimal dan menghindari pemborosan akibat pergeseran data. Dengan memahami cara kerja penunjuk head dan tail, seorang programmer dapat menentukan jenis queue yang paling tepat sesuai dengan kebutuhan dan karakteristik sistem yang akan dikembangkan.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
