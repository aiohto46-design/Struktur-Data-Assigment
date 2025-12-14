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
