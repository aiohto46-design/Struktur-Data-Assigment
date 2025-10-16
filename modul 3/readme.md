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
<img width="1374" height="950" alt="image" src="https://github.com/user-attachments/assets/0e96e068-6d16-4b95-a6c1-1700040b80b3" />

Program ini menyimpan data mahasiswa maximal sebanyak sepuluh orang kedalam array yang berisi nama, nim, nilai uts, uas, tugas dan nilai akhir, nilai akhir akan di hitung menggunakan rumus pada code (hitung) yang sudah di buat, jadi intinya program ini melatih penggunaan array of struct, input/output dan fungsi perhitungan sederhana untuk menghitung nilai akhir mahasiswa.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/8f13324c-89d2-4754-9400-a4614d6a3f9d" />


### 2. [Nama Matkul]

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
<img width="1147" height="169" alt="image" src="https://github.com/user-attachments/assets/f5f7ae41-0410-458a-beef-85ec5c75b3de" />


Program ini menggunakan ADT (Abstract Data Type) untuk menyimpan dan menampilkan data pelajaran. Struct Pelajaran berisi nama dan kode mapel, lalu ada fungsi create_pelajaran untuk membuat data baru dan tampil_pelajaran untuk menampilkannya. Program ini menunjukkan cara memisahkan data dan fungsinya agar kode lebih rapi dan terstruktur.

#### Full code Screenshot:
<img width="1914" height="1004" alt="image" src="https://github.com/user-attachments/assets/e9562d1d-f244-4357-b7d6-c399ca5c29fd" />
<img width="1906" height="1013" alt="image" src="https://github.com/user-attachments/assets/55c95bd3-54ad-4a7b-84ac-8708e89289c8" />
<img width="1918" height="1055" alt="image" src="https://github.com/user-attachments/assets/3b56ec3d-7a7d-4147-90fd-739e153cebe9" />


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
<img width="1535" height="556" alt="image" src="https://github.com/user-attachments/assets/110493da-96bd-4402-9334-aef498fcfdbc" />

Program ini menampilkan cara menukar nilai antar elemen array 2 dimensi dan antar variabel menggunakan pointer. Fungsi tukarPosisi menukar elemen dua array di posisi tertentu, sedangkan tukarPointer menukar nilai dua variabel lewat pointer. Program ini menunjukkan penggunaan array, fungsi, dan pointer dalam C++. 

#### Full code Screenshot:
<img width="1919" height="1011" alt="image" src="https://github.com/user-attachments/assets/70c45fad-5ed0-48c6-8f3a-1e45d0ba4d3f" />



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. pandangan ku pada minggu ketiga, setelah memasuki modul 3 konsep ADT (Abtract Data Type) membantu agar membuat program terlihat rapi dan mudah untuk di pahami, dengan memisahkan data dan fungsi di file yang berbeda membuat program menjadi terstruktur, konsep ini mempermudah mengelola dan mengubah data tanpa terganggu bagian lain.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
