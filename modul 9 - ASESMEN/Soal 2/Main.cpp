#include <iostream>
#include "DLLPlaylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    Song S1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    Song S2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    Song S3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};

    insertLast(L, S1);
    insertLast(L, S2);
    insertLast(L, S3);

    cout << "\n=== LIST AWAL ===\n";
    viewList(L);

    Song temp;
    deleteLast(L, temp);

    cout << "\n=== SETELAH deleteLast ===\n";
    viewList(L);

    cout << "\n=== UPDATE POSISI 2 ===\n";
    updateAtPosition(L, 2);

    cout << "\n=== LIST SETELAH UPDATE ===\n";
    viewList(L);
    address pos2 = L.head->next;

    Song S4 = {"Senandung", "Mira", 175, 120, 4.0};
    insertBefore(L, pos2, S4);

    cout << "\n=== SETELAH insertBefore POSISI 2 ===\n";
    viewList(L);

    cout << "\n=== UPDATE BEFORE POSISI 2 ===\n";
    updateBefore(L, pos2);

    cout << "\n=== HASIL UPDATE BEFORE ===\n";
    viewList(L);

    address pos3 = L.head->next->next;
    deleteBefore(L, pos3, temp);

    cout << "\n=== SETELAH deleteBefore POSISI 3 ===\n";
    viewList(L);

    cout << "\n=== SEARCH PopularityScore 150 - 300 ===\n";
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}

