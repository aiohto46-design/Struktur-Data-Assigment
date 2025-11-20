#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Node *prev;
    Node *next;
};

typedef Node* address;

struct List {
    address head;
    address tail;
};

bool isEmpty(List L) {
    return (L.head == nullptr);
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
        L.tail->next = P;
        P->prev = L.tail;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q == nullptr) return;
    address P = allocate(S);

    P->next = Q->next;
    P->prev = Q;

    if (Q->next != nullptr)
        Q->next->prev = P;
    else
        L.tail = P;

    Q->next = P;
}

void insertBefore(List &L, address Q, Song S) {
    if (Q == nullptr) return;

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

void deleteFirst(List &L, Song &S) {
    if (isEmpty(L)) return;

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

void deleteLast(List &L, Song &S) {
    if (isEmpty(L)) return;

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

void deleteAfter(List &L, address Q, Song &S) {
    if (Q == nullptr || Q->next == nullptr) return;

    address P = Q->next;
    S = P->info;

    Q->next = P->next;
    if (P->next != nullptr)
        P->next->prev = Q;
    else
        L.tail = Q;

    deallocate(P);
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q == nullptr || Q->prev == nullptr) return;

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

float getPopularityScore(Song S) {
    return 0.8f * S.PlayCount + 20.0f * S.Rating;
}

void updateAtPosition(List &L, int posisi) {
    if (isEmpty(L)) return;

    address P = L.head;
    int idx = 1;

    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != nullptr) {
        cout << "Masukkan Title baru: ";
        cin.ignore();
        getline(cin, P->info.Title);

        cout << "Masukkan Artist baru: ";
        getline(cin, P->info.Artist);

        cout << "Masukkan DurationSec baru: ";
        cin >> P->info.DurationSec;

        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;

        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void updateBefore(List &L, address Q) {
    if (Q == nullptr || Q->prev == nullptr) return;

    address P = Q->prev;

    cout << "Masukkan Title baru: ";
    cin.ignore();
    getline(cin, P->info.Title);

    cout << "Masukkan Artist baru: ";
    getline(cin, P->info.Artist);

    cout << "Masukkan DurationSec baru: ";
    cin >> P->info.DurationSec;

    cout << "Masukkan PlayCount baru: ";
    cin >> P->info.PlayCount;

    cout << "Masukkan Rating baru: ";
    cin >> P->info.Rating;
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int pos = 1;

    while (P != nullptr) {
        float score = getPopularityScore(P->info);

        cout << pos << ". "
             << P->info.Title << " | "
             << P->info.Artist << " | Dur:" << P->info.DurationSec
             << " | Play:" << P->info.PlayCount
             << " | Rating:" << P->info.Rating
             << " | Score:" << score << endl;

        P = P->next;
        pos++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address P = L.head;
    int pos = 1;
    bool found = false;

    while (P != nullptr) {
        float score = getPopularityScore(P->info);

        if (score >= minScore && score <= maxScore) {
            found = true;
            cout << pos << ". " << P->info.Title
                 << " | Score: " << score << endl;
        }
        P = P->next;
        pos++;
    }

    if (!found)
        cout << "Tidak ada lagu dalam rentang tersebut.\n";
}

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
