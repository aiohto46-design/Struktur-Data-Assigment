#include <iostream>
#include <string>
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
    int head;
    int tail;
};

bool isEmpty(QueueEkspedisi &Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFull(QueueEkspedisi &Q) {
    return Q.tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.dataPaket[Q.tail] = data;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        for (int i = Q.head; i < Q.tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.tail--;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << "Kode Resi: " << Q.dataPaket[i].KodeResi << endl;
            cout << "Nama Pengirim: " << Q.dataPaket[i].NamaPengirim << endl;
            cout << "Berat Barang: " << Q.dataPaket[i].BeratBarang << endl;
            cout << "Tujuan: " << Q.dataPaket[i].Tujuan << endl;
            cout << endl;
        }
    }
}

int TotalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        return 0;
    }
    int total = 0;
    for (int i = Q.head; i <= Q.tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "--- Komaniya Ekspress ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan queue paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            Paket p;
            cout << "Kode Resi: ";
            cin >> p.KodeResi;
            cout << "Nama Pengirim: ";
            cin >> p.NamaPengirim;
            cout << "Berat Barang: ";
            cin >> p.BeratBarang;
            cout << "Tujuan: ";
            cin >> p.Tujuan;
            enQueue(Q, p);
        }

        if (pilihan == 2) {
            deQueue(Q);
        }

        if (pilihan == 3) {
            viewQueue(Q);
        }

        if (pilihan == 4) {
            int total = TotalBiayaPengiriman(Q);
            cout << "Total Biaya Pengiriman: Rp " << total << endl;
        }

    } while (pilihan != 5);

    return 0;
}

