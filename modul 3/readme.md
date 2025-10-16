# <h1 align="center">Laporan Praktikum Modul 3 Abstract Data Type (ADT)</h1>
<p align="center">HAFIDH NURUDDIN AKBAR</p>

## Dasar Teori

ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam
sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT
merupakan definisi STATIK.
Definisi type dari sebuah ADT dapat mengandung sebuah definisi ADT lain. Misalnya :

- ADT waktu yang terdiri dari ADT JAM dan ADT DATE

- Garis terdiri dari duah buah ADT POINT

SEGI4 yang terdiri dari pasangan dua buah POINT (Top,Left) dan (Bottom,Right)
TYPE diterjemahkan menjadi type terdefinisi dalam bahasa yang bersangkutan. Jika dalam bahasa C
menggunakan struct PRIMITIF, dalam konteks prosedural, diterjemahkan menjadi fungsi atau
prosedur. 

## Guided 

### 1. [mahasiswa.h]

```C++
//array
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputmhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif

```
program digunakan untuk membuat struct mahasiswa yang terdiri dari char nim dan nilai1, nilai2.
### 2. [mahasiswa.cpp]

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputmhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;

}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) /2.0;
}
```
program ini digunakan untuk menyimpan void input yang berfungsi untuk menampilkan input nama, nilai1, dan nilai2, disini juga ada proses untuk menghitung rata rata dari nilai1 dan nilai2 kemudian di bagi 2.0.

### 3. [main.cpp]

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputmhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}

```
program ini merupakan file utama untuk menjalankan dan menyatukan semua program yang sudah di buat di atas.
.

## Unguided 

### 1. [Nilai Mahasiswa]

### Code
```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitung(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitung(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n--- Data Mahasiswa ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
        cout << "---------------------------\n";

    }

    return 0;
}

```
#### Output:
<img width="344" height="508" alt="image" src="https://github.com/user-attachments/assets/befe6e42-fc4e-41fe-b1aa-ea70114f6a66" />

Program ini menyimpan data mahasiswa maximal sebanyak sepuluh orang kedalam array yang berisi nama, nim, nilai uts, uas, tugas dan nilai akhir, nilai akhir akan di hitung menggunakan rumus pada code (hitung) yang sudah di buat, jadi intinya program ini melatih penggunaan array of struct, input/output dan fungsi perhitungan sederhana untuk menghitung nilai akhir mahasiswa.

#### Full code Screenshot:
<img width="500" height="753" alt="image" src="https://github.com/user-attachments/assets/6e1b4a51-d338-412f-9f55-384618e8dbdc" />


### 2. [Nama Matkul]

### Code
```C++
//pelajaran.h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_pelajaran(string nama, string kode);
void tampil_pelajaran(Pelajaran pel);

#endif
```
berisi deklarasi struct dan fungsi, struct ini dipakai untuk menyimpan data nama pelajaran.
```C++
//pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Nilai          : " << pel.kodeMapel << endl;
}D
```
berisi implementasi fungsi fungsi yang ada di header.
```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    Pelajaran pel = create_pelajaran(namaPel, kodePel);

    tampil_pelajaran(pel);

    return 0;
}
```
file utama untuk menjalankan program.

#### Output:
![WhatsApp Image 2025-10-16 at 20 06 44](https://github.com/user-attachments/assets/8d5b8212-396e-49da-9a46-3a2a0770703b)

Program ini menggunakan ADT (Abstract Data Type) untuk menyimpan dan menampilkan data pelajaran. Struct Pelajaran berisi nama dan kode mapel, lalu ada fungsi create_pelajaran untuk membuat data baru dan tampil_pelajaran untuk menampilkannya. Program ini menunjukkan cara memisahkan data dan fungsinya agar kode lebih rapi dan terstruktur.

#### Full code Screenshot:
![WhatsApp Image 2025-10-16 at 20 07 39](https://github.com/user-attachments/assets/364dbe29-a8fb-4fc6-841f-376c2d3aed51)
![WhatsApp Image 2025-10-16 at 20 07 24](https://github.com/user-attachments/assets/d532f425-258e-4112-af83-d672fb083fac)
![WhatsApp Image 2025-10-16 at 20 07 05](https://github.com/user-attachments/assets/e1f825e0-26a1-43c6-bfb3-f19549be14ed)


### 3. [Tukar array 2D]

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarPosisi(A, B, 0, 0);

    cout << "\nSetelah tukar posisi (baris 1 kolom 1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    int x = 100, y = 200;
    int* px = &x;
    int* py = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(px, py);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
```
#### Output:
<img width="526" height="363" alt="image" src="https://github.com/user-attachments/assets/b7ac85bd-1408-4960-8ef0-6961552c79af" />

Program ini menampilkan cara menukar nilai antar elemen array 2 dimensi dan antar variabel menggunakan pointer. Fungsi tukarPosisi menukar elemen dua array di posisi tertentu, sedangkan tukarPointer menukar nilai dua variabel lewat pointer. Program ini menunjukkan penggunaan array, fungsi, dan pointer dalam C++. 

#### Full code Screenshot:
<img width="584" height="767" alt="image" src="https://github.com/user-attachments/assets/5365b898-4602-417f-9e64-1f3714efad6c" />



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. pandangan ku pada minggu ketiga, setelah memasuki modul 3 konsep ADT (Abtract Data Type) membantu agar membuat program terlihat rapi dan mudah untuk di pahami, dengan memisahkan data dan fungsi di file yang berbeda membuat program menjadi terstruktur, konsep ini mempermudah mengelola dan mengubah data tanpa terganggu bagian lain.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
