#include "buah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = nullptr;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Apel", 100, 20000);
    nodeB = alokasi("Cemangka", 75, 21000);
    nodeC = alokasi("Apple", 87, 20000);
    nodeD = alokasi("Tomato", 43, 21000);
    nodeE = alokasi("Duren", 70, 50000);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node: " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kalpa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 50, 1000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeA, nodeB);

     cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

     deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    return 0;
}
