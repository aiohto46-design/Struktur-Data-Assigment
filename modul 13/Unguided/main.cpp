#include <iostream>
#include "multi.h"
using namespace std;

int main() {
    List L, A, B, L2;
    address P1 = NULL;
    address P2 = NULL;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl << endl;

    x = {"Danu", "04", 'L', 4.0};
    P1 = alokasi(x);
    insertFirst(L, P1);

    x = {"Fahmi", "06", 'L', 3.45};
    P1 = alokasi(x);
    insertLast(L, P1);

    x = {"Bobi", "02", 'L', 3.71};
    P1 = alokasi(x);
    insertFirst(L, P1);

    x = {"Ali", "01", 'L', 3.3};
    P1 = alokasi(x);
    insertFirst(L, P1);

    x = {"Gita", "07", 'P', 3.75};
    P1 = alokasi(x);
    insertLast(L, P1);

    x.nim = "07";
    P1 = findElm(L, x);
    x = {"Cindi", "03", 'P', 3.5};
    P2 = alokasi(x);
    insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    x = {"Hani", "08", 'P', 3.3};
    P2 = alokasi(x);
    insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    x = {"Eli", "05", 'P', 3.4};
    P2 = alokasi(x);
    insertAfter(L, P1, P2);

    printInfo(L);

    return 0;
}
