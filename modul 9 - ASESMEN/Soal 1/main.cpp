#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct SLLNode {
    Product info;
    SLLNode *next;
};

struct SLLList {
    SLLNode *head;
};

typedef SLLNode* address;

bool isEmpty(const SLLList &L) {
    return L.head == nullptr;
}

void createList(SLLList &L) {
    L.head = nullptr;
}

address allocate(const Product &P) {
    address p = new SLLNode;
    p->info = P;
    p->next = nullptr;
    return p;
}

void deallocate(address addr) {
    delete addr;
}

void insertFirst(SLLList &L, const Product &P) {
    address p = allocate(P);
    p->next = L.head;
    L.head = p;
}

void insertLast(SLLList &L, const Product &P) {
    address p = allocate(P);
    if (isEmpty(L)) {
        L.head = p;
    } else {
        address q = L.head;
        while (q->next) q = q->next;
        q->next = p;
    }
}

void insertAfter(SLLList &L, address Q, const Product &P) {
    if (Q == nullptr) return;
    address p = allocate(P);
    p->next = Q->next;
    Q->next = p;
}

void deleteFirst(SLLList &L, Product &P) {
    if (isEmpty(L)) return;
    address p = L.head;
    P = p->info;
    L.head = p->next;
    deallocate(p);
}

void deleteLast(SLLList &L, Product &P) {
    if (isEmpty(L)) return;
    address cur = L.head, prev = nullptr;
    if (cur->next == nullptr) {
        P = cur->info;
        L.head = nullptr;
        deallocate(cur);
        return;
    }
    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    P = cur->info;
    deallocate(cur);
}

void deleteAfter(SLLList &L, address Q, Product &P) {
    if (Q == nullptr || Q->next == nullptr) return;
    address p = Q->next;
    P = p->info;
    Q->next = p->next;
    deallocate(p);
}

void updateAtPosition(SLLList &L, int posisi, const Product &P) {
    if (posisi < 1) return;
    address cur = L.head;
    int idx = 1;
    while (cur && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur) cur->info = P;
}

float HargaAkhir(const Product &p) {
    return p.HargaSatuan * (1.0f - p.DiskonPersen / 100.0f);
}

void viewList(const SLLList &L) {
    address cur = L.head;
    int idx = 1;
    cout << fixed << setprecision(2);
    if (isEmpty(L)) {
        cout << "List kosong\n";
        return;
    }
    while (cur) {
        const Product &pr = cur->info;
        cout << idx << ". " << pr.Nama 
             << " | SKU: " << pr.SKU
             << " | Jumlah: " << pr.Jumlah
             << " | Harga: " << pr.HargaSatuan
             << " | Diskon: " << pr.DiskonPersen
             << " | Harga Akhir: " << HargaAkhir(pr)
             << "\n";
        cur = cur->next;
        idx++;
    }
    cout << "\n";
}

void searchByFinalPriceRange(const SLLList &L, float minPrice, float maxPrice) {
    address cur = L.head;
    int idx = 1;
    bool found = false;
    cout << fixed << setprecision(2);
    while (cur) {
        float ha = HargaAkhir(cur->info);
        if (ha >= minPrice && ha <= maxPrice) {
            cout << "Posisi " << idx << ": " 
                 << cur->info.Nama 
                 << " | HargaAkhir: " << ha << "\n";
            found = true;
        }
        cur = cur->next;
        idx++;
    }
    if (!found) cout << "Produk tidak ditemukan.\n";
}

void MaxHargaAkhir(const SLLList &L) {
    if (isEmpty(L)) {
        cout << "List kosong\n";
        return;
    }
    float maxVal = -1e9;
    address cur = L.head;
    while (cur) {
        float ha = HargaAkhir(cur->info);
        if (ha > maxVal) maxVal = ha;
        cur = cur->next;
    }
    cout << "Produk dengan harga akhir maksimum (" << maxVal << "):\n";
    cur = L.head;
    int idx = 1;
    while (cur) {
        if (abs(HargaAkhir(cur->info) - maxVal) < 1e-4) {
            cout << "Posisi " << idx << ": " 
                 << cur->info.Nama 
                 << " | SKU: " << cur->info.SKU << "\n";
        }
        cur = cur->next;
        idx++;
    }
}

int main() {
    SLLList L;
    createList(L);

    insertLast(L, {"Pulpen", "A001", 20, 2500, 0});
    insertLast(L, {"Buku Tulis", "A002", 15, 5000, 10});
    insertLast(L, {"Penghapus", "A003", 30, 1500, 0});

    cout << "LIST AWAL\n";
    viewList(L);

    Product del;
    deleteFirst(L, del);

    cout << "SETELAH deleteFirst\n";
    viewList(L);

    Product baru = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, baru);

    cout << "SETELAH UPDATE POSISI KE-2\n";
    viewList(L);

    cout << "SEARCH HARGA AKHIR 2000 - 7000\n";
    searchByFinalPriceRange(L, 2000, 7000);

    cout << "MAX HARGA AKHIR\n";
    MaxHargaAkhir(L);

    return 0;
}


