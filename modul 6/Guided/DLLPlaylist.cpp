#include "DLLPlaylist.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void deallocate(address P) {
    delete P;
}

float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q != nullptr) {
        address P = allocate(S);
        P->next = Q->next;
        P->prev = Q;

        if (Q->next != nullptr)
            Q->next->prev = P;
        else
            L.tail = P;

        Q->next = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q != nullptr) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;

            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.head;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.head = P->next;
            L.head->prev = nullptr;
        }
        deallocate(P);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.tail;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.tail = P->prev;
            L.tail->next = nullptr;
        }
        deallocate(P);
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->next != nullptr) {
        address P = Q->next;
        S = P->info;

        Q->next = P->next;
        if (P->next != nullptr)
            P->next->prev = Q;
        else
            L.tail = Q;

        deallocate(P);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;
        S = P->info;

        if (P == L.head) {
            deleteFirst(L, S);
        } else {
            P->prev->next = Q;
            Q->prev = P->prev;
            deallocate(P);
        }
    }
}

void updateAtPosition(List &L, int posisi) {
    int idx = 1;
    address P = L.head;

    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != nullptr) {
        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void updateBefore(List &L, address Q) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;

        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int idx = 1;

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        cout << idx << ". "
             << P->info.Title << " | " << P->info.Artist
             << " | " << P->info.DurationSec << "s | PC: "
             << P->info.PlayCount << " | Rating: "
             << P->info.Rating << " | PopularityScore: "
             << pop << endl;

        P = P->next;
        idx++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address P = L.head;
    int idx = 1;

    cout << "\nHasil searching PopularityScore in [" 
         << minScore << ", " << maxScore << "]\n";

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        if (pop >= minScore && pop <= maxScore) {
            cout << idx << ". " << P->info.Title 
                 << " | PopularityScore: " << pop << endl;
        }

        P = P->next;
        idx++;
    }
}