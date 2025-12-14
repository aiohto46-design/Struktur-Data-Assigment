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
