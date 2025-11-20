#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {

    SLLList L;
    createList(L);

    insertLast(L, {"Pulpen", "A001", 20, 2500, 0});
    insertLast(L, {"Buku Tulis", "A002", 15, 5000, 10});
    insertLast(L, {"Penghapus", "A003", 30, 1500, 0});

    cout << "\nLIST AWAL\n";
    viewList(L);

    Product del;
    deleteFirst(L, del);

    cout << "\n -- SETELAH deleteFirst -- \n";
    viewList(L);

    Product baru = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, baru);

    cout << "\n list setelah update update posisi ke-2 \n";
    viewList(L);
    
    cout << "\n search harga akhir 2000 - 7000 \n";
    searchByFinalPriceRange(L, 2000, 7000);

    cout << " produk harga akhir maksimum \n";
    MaxHargaAkhir(L);

    return 0;

}
