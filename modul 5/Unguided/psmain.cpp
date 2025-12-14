#include "listps.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi("PS3", 2, 8000));
    insertLast(L, alokasi("PS4", 3, 12000));
    insertLast(L, alokasi("PS5", 1, 15000));
    insertLast(L, alokasi("PS2", 4, 6000));

    cout << "=== Data Sewa PlayStation ===" << endl;
    printInfo(L);

    cout << "\nCari PS 'PS4':" << endl;
    address cari = findPS(L, "PS4");
    if (cari != Nil)
        cout << "PS ditemukan! Durasi: " << cari->info.durasi << " jam, Harga/jam: " << cari->info.harga << endl;
    else
        cout << "PS tidak ditemukan." << endl;

    cout << "\nUpdate PS 'PS3' jadi durasi 5 jam dan harga 9000/jam" << endl;
    updatePS(L, "PS3", 5, 9000);

    cout << "\n=== Data Setelah Update ===" << endl;
    printInfo(L);

    int total = totalPendapatan(L);
    cout << "\nTotal pendapatan dari semua PS: Rp " << total << endl;

    return 0;
}