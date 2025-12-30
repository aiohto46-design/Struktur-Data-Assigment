# <h1 align="center">Laporan Praktikum Modul 10 Tree </h1>
<p align="center">Hafidh Nuruddin Akbar</p>

## Dasar Teori
- Pengertian Rekursif

Secara harfiah, rekursif adalah suatu proses pengulangan yang dilakukan dengan cara kesamaan-diri, yaitu suatu prosedur atau fungsi yang memanggil dirinya sendiri secara langsung maupun tidak langsung. Dalam pemrograman, rekursif digunakan untuk menyelesaikan permasalahan dengan cara memecah masalah besar menjadi submasalah yang lebih kecil hingga mencapai kondisi dasar (base case).
Prosedur dan fungsi merupakan bentuk subprogram yang sangat bermanfaat dalam pemrograman, khususnya pada program atau proyek berskala besar. Salah satu teknik yang sering digunakan dalam subprogram adalah rekursi, karena dapat menyederhanakan logika penyelesaian masalah tertentu.
Manfaat penggunaan subprogram, termasuk subprogram rekursif, antara lain sebagai berikut:
1. Meningkatkan readability, yaitu mempermudah pembacaan dan pemahaman kode program.
2. Meningkatkan modularity, yaitu memecah program yang kompleks menjadi modul-modul atau bagian-bagian kecil sesuai dengan fungsinya, sehingga memudahkan proses pengecekan, pengujian (testing), dan pelokalan kesalahan.
3. Meningkatkan reusability, yaitu subprogram dapat digunakan kembali berkali-kali hanya dengan memanggilnya, tanpa perlu menuliskan ulang perintah-perintah yang sama.

Dengan demikian, penggunaan rekursif dalam subprogram dapat membantu menghasilkan program yang lebih terstruktur, mudah dipahami, dan efisien dalam pengembangan maupun pemeliharaan.
## Guided

### 1. [bst.h]

```C++
#ifndef BST_H
#define BST_H

#define Nil NULL

// Struktur node BST
struct BST {
    int angka;
    BST *left;
    BST *right;
};

// Tipe data
typedef BST* node;
typedef BST* BinTree;

// Fungsi dasar
bool isEmpty(BinTree tree);
void createTree(BinTree &tree);

// Alokasi & dealokasi
node alokasi(int angkaInput);
void dealokasi(node nodeHapus);

// Operasi BST
void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angkaCari);

// Traversal
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

// Delete
bool deleteNode(BinTree &tree, int angka);

// Utility
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);

// Informasi tree
int size(BinTree tree);
int height(BinTree tree);

#endif
```
Berisi pendefinisian struktur node serta deklarasi prototipe fungsi BST yang berfungsi sebagai penghubung antara main.cpp dan bst.cpp.

### 2. [bst.cpp]

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree
```

Merupakan file implementasi yang memuat logika dan algoritma Binary Search Tree (BST). Pada file ini didefinisikan seluruh fungsi BST, meliputi pembuatan tree, penyisipan node secara rekursif, pencarian data, traversal (preorder, inorder, dan postorder), penghapusan node berdasarkan kondisi (leaf, satu child, atau dua child), serta perhitungan ukuran dan tinggi tree. File ini menjadi inti dari proses pengolahan struktur data BST.

### 3. [main.cpp]

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Merupakan file program utama yang berisi fungsi main() beserta menu interaktif. File ini berperan sebagai antarmuka pengguna untuk memanggil fungsi-fungsi BST yang didefinisikan pada bst.cpp melalui bst.h. Melalui menu yang tersedia, pengguna dapat melakukan operasi seperti insert, delete, search, traversal, serta operasi BST lainnya.

## Unguided 
### 1. [bstree.h]

```C++
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#define NIL NULL
#include <iostream>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int tahunbuat;
};

typedef kendaraan infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);

#endif
```
### 2. [bstree.cpp]
```C++
#include "doublelist.h"

void CreateList(List &L) {
    L.first = NIL;
    L.last = NIL;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NIL;
    P->prev = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

void insertLast(List &L, address P) {
    if (L.first == NIL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NIL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahunbuat << endl;
        cout << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NIL) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return NIL;
}

void deleteFirst(List &L) {
    if (L.first != NIL) {
        address P = L.first;

        if (L.first == L.last) {
            L.first = L.last = NIL;
        } else {
            L.first = P->next;
            L.first->prev = NIL;
        }
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != NIL) {
        address P = L.last;

        if (L.first == L.last) {
            L.first = L.last = NIL;
        } else {
            L.last = P->prev;
            L.last->next = NIL;
        }
        dealokasi(P);
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NIL && Prec->next != NIL) {
        address P = Prec->next;
        Prec->next = P->next;
        if (P->next != NIL) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        dealokasi(P);
    }
}
```
### 3. [main.cpp]

```C++
#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;
    string nopolInput;

    // Input 4 kali sesuai contoh modul
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        // Cek duplikasi
        if (findElm(L, x.nopol) != NIL) {
            cout << "nomor polisi sudah terdaftar\n\n";
            // skip input warna/tahun kalau dupe
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.tahunbuat;

        cout << endl;

        P = alokasi(x);
        insertLast(L, P);
    }

    cout << "DATA LIST 1\n";
    printInfo(L);
    cout << endl;


    // ===== SOAL NOMOR 2 : Find D001 =====
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolInput;

    address found = findElm(L, nopolInput);
    if (found != NIL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahunbuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << endl;


    // ===== SOAL NOMOR 3 : Hapus =====
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolInput;

    address target = findElm(L, nopolInput);

    if (target != NIL) {
        if (target == L.first) {
            deleteFirst(L);
        } else if (target == L.last) {
            deleteLast(L);
        } else {
            deleteAfter(L, target->prev);
        }
        cout << "Data dengan nomor polisi " << nopolInput << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
```

#### Output:
<img width="1020" height="920" alt="image" src="https://github.com/user-attachments/assets/ead53e62-fdab-42d5-84a6-fa2a90b31401" />

Program ini dibuat untuk mengelola data kendaraan menggunakan Doubly Linked List.
Setiap node menyimpan nomor polisi, warna kendaraan, dan tahun pembuatan.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/cb3d1f32-c50b-487f-b408-ae51c39b75b6" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/362d23f7-1a6d-48df-851b-5f8361dffdda" />

<img width="1917" height="1079" alt="image" src="https://github.com/user-attachments/assets/cae371a4-c2bb-432e-a55a-fcb7a56fb7ca" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalian dari hasil praktikum dan pembelajaran yang didapat[1]. Modul 10 pada modul ini materi yang di sampaikan itu tentang Binary search Tree, Melalui praktikum Binary Search Tree (BST), mendapatkan pemahaman tentang struktur data tree dan penerapan rekursi dalam proses insert, search, traversal, dan delete. Praktikum ini menunjukkan bahwa BST mempermudah pengelolaan data secara terurut dan efisien. Selain itu, pembelajaran ini meningkatkan pemahaman tentang struktur data non-linear dan pemrograman yang modular.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
