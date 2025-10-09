# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori

mengenal bahasa pemrograman C++, bahasa C++ merupakan bahasa yang unik yang di mana memerlukkan code khusus untuk memamnggil suatu character agar bisa di compile dan bisa di baca oleh komputer seperti #include <iostream> digunakan untuk mendeklarasikan library yang akan digunakan dalam program, bahasa C++ cukup banyak di gemari karena mudah di gunakan oleh banyak orang.

## Guided 

### 1. [Cetak text]

C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}

program ini dibuat menggunakan bahasa pemrograman C++, program akan menghasilkan output sesuai masukkan yang ditulis oleh pengguna "Hello World".

### 2. [Input Output]

C++
#include <iostream>
using namespace std;

int main() {
    int n;
    const float pi = 3.14;

    cout << "masukan angka: ";
    cin >> n;

    cout << "angka dikeluarkan: " << n << endl;
    cout << "nilai konstanta pi: " << pi << endl;
    return 0;

}

program input output jadi pengguna menginput variable bertipe int dengan const 3,14 cout di gunakan untuk wadah input dan cin sebagai wadah output program.

### 3. [Operator Dasar]

C++
//operator
#include <iostream>

using namespace std;

int main() {
    int a;
    int b;

    cout << "Masukkan angka1: ";
    cin >> a;
    cout << "Masukkan angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //operator logika 
    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;

    return 0;
}

program ini menampilkan bagaimana operasi dasar dan oprasi logika di jalankan penggunaan tanda +-*/% merupakan sistem operasi dasar.

### 4. [Percabangan]

C++
#include <iostream>

using namespace std;

int main() {
    int angka1 = 20;
    int angka2 = 20;

    if (angka1 > angka2) {
        cout << "Angka1 lebih besar dari angka2" << endl;
    }else if (angka1 < angka2) {
        cout << "angka1 lebih kecil dari angka2" << endl;
    }else {
        cout << "angka1 sama dengan angka2" << endl;
    }

    return 0;
}

program ini menggunakan if else untuk bisa beroperasi menentukkan output mana yang sesuai dengan inputan pengguna.

### 5. [Perulangan for]

C++
#include <iostream>

using namespace std;

int main() {
    int i;
    int j;

    for (int i = 0; i <= 10; i++) {
        cout << i << "-" ;
    }

    cout << endl;

    for (int j = 20; j >= 10; j--) {
        cout << j << "-" ;
    }

    return 0;
}

program akan melakukkan perulangan menggunakan for pada inputan pengguna.

### 6. [Perulangan WhileDo]

C++
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int j = 20;

    while (i <= 10) {
        cout << i << "-";
        i++;
    }

    cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j <=10);

    return 0;
}

program sama melakukkan perulangan beda nya akan terus berjalan jika kondisi nya benar dan akan berhenti jika sudah false.

### 7. [Structre]

C++
#include <iostream>
#include <string>
using namespace std;
struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    int jumlah;

    cout << "masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    //input data menggunakan loop
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "Umur: ";
        cin >> mhs[i].umur;
    }
    
    //tampilkan data
    cout << "\n === Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i+1 
             << "| Nama: |" << mhs[i].nama
             << "| Umur: |" << mhs[i].umur << endl;
    }
    return 0;
}

program ini merupakan implementasi dari struct yang bisa memuat berbagai tipe variable yang nantinya di gunakan dalam program.

## Unguided 

### 1. [Operasi Dasar]

C++
#include <iostream>
using namespace std;

int main(){
    float a;
    float b;

    //Inputan
     cout << "masukkan angka 1: " << endl;
     cin >> a;
     cout << "masukkan angka 2: " << endl;
     cin >> b;

    //Operasi Dasar
    cout << "Hasil Penjumlahan = " << (a+b) << endl;
    cout << "Hasil Pengurangan = " << (a-b) << endl;
    cout << "Hasil Perkalian = " << (a*b) << endl;
    cout << "Hasil Pembagian = " << (a/b) << endl;

    return 0;
}

#### Output:
<img width="1379" height="284" alt="image" src="https://github.com/user-attachments/assets/51a8cf20-135c-4bb4-8f1d-c7d091ea2a86" />

Kode di atas merupakan kode untuk membuat bilangan bertipe float bisa melakukkan operasi dasar penjumlahan, pengurangan, perkalian dan pembagian, program akan meminta 2 inputan bertipe float lalu program akan mengeksekusi operasi dasar yang sudah di siapkan dan program akan langsung menghasil kan output hasil dari oprasi dasar tersebut.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/6a045365-2bcb-4b36-9e66-c57fcde87f3d" />


### 2. [Mengubah Angka Menjadi String]

C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "";
    cin >> n;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    string hasil;

    if (n < 12) {
        hasil = satuan[n];
    } else if (n < 20) {
        hasil = satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        hasil = satuan[puluh] + " puluh";
        if (sisa != 0) hasil += " " + satuan[sisa];
    } else if (n == 100) {
        hasil = "seratus";
    } else {
        hasil = "angka melebihi kapasitas ";
    }

    cout << n << " : " << hasil << endl;

    return 0;
}

#### Output:
<img width="1377" height="303" alt="image" src="https://github.com/user-attachments/assets/e3aa73c0-670d-486c-9c64-37f1a2bd2983" />


Code di atas digunakan untuk mengubah angka atau tipe integer menjadi string, jadi si program akan meminta input berupa int lalu program akan mengecek di bagian if else apakah sesuai dengan aturan jika iya makan angka tersebut akan diubah lalu jika angka puluhan maka akan ada tambahan berupa string yang sudah di siapkan di string satuan (buat string satuan []) dan jika angkanya melebihi kapasitas maka output yang keluar "angka melebihi kapasitas".

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/e27a31c1-a608-4d4d-92d8-f5b0aa638767" />


### 3. [Buat Segitiga Angka]

C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    if (!(cin >> n)) return 0;

    for (int i = n; i >= 0; i--) {
        // Spasi di depan
        for (int s = 0; s < n - i; s++) cout << "  ";

        //Angka menurun
        for (int a = i; a >= 1; a--) cout << a << " ";

        // Bintang di tengah
        cout << "* ";

        // Angka menaik
        for (int b = 1; b <= i; b++) cout << b << " ";

        cout << '\n';
    }

    return 0;
}


#### Output:
<img width="1359" height="272" alt="image" src="https://github.com/user-attachments/assets/73b7a654-53b6-47d9-ac51-aba9c1c2be62" />

Kode ini membuat urutan angka yang berbentuk segitiga sama sisi, pengguna akan menginput variable bertipe int lalu akan masuk ke perulangan yang akan menulis ulang angka yang di inputkan dari yang terbesar sampai terkecil dengan di batasi tanda bintang setiap for memilki fungsi masing-masing untuk bisa membuat bentuk segitiga.

#### Full code Screenshot:
<img width="1919" height="1078" alt="image" src="https://github.com/user-attachments/assets/8b954c7e-df0a-4c50-ba9c-28200fb562f2" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. pandangan ku di minggu pertama praktikum saya jadi bisa mengenal lebih dalam bahasa pemrograman C++ ini dari penggunaan dasar pemrograman, structure program, running code, compile code dan bentukan variblenya dengan belajar bahasa baru bisa menambah pengetahuan kalau bahasa program itu sangat beragam dan berbeda beda structure dan pembuatannya.   

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar

Referensi
