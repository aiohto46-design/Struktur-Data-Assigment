#include "Stack.h"

void init(Stack &S) {
    S.idxTop = -1;
}

bool empty(Stack S) {
    return S.idxTop == -1;
}

bool full(Stack S) {
    return S.idxTop == MAX_STACK - 1;
}

void pushData(Stack &S, Item x) {
    if (!full(S)) {
        S.idxTop++;
        S.elemen[S.idxTop] = x;
    }
}

Item popData(Stack &S) {
    if (!empty(S)) {
        Item hasil = S.elemen[S.idxTop];
        S.idxTop--;
        return hasil;
    }
    return -1;
}

void tampil(Stack S) {
    cout << "Isi Stack (atas ke bawah): ";
    for (int i = S.idxTop; i >= 0; i--) {
        cout << S.elemen[i] << " ";
    }
    cout << endl;
}

void reverse(Stack &S) {
    Stack bantu;
    init(bantu);

    while (!empty(S)) {
        pushData(bantu, popData(S));
    }

    S = bantu;
}

void pushUrut(Stack &S, Item x) {
    Stack sementara;
    init(sementara);

    while (!empty(S) && S.elemen[S.idxTop] < x) {
        pushData(sementara, popData(S));
    }

    pushData(S, x);

    while (!empty(sementara)) {
        pushData(S, popData(sementara));
    }
}

void bacaInput(Stack &S) {
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') break;

        if (ch >= '0' && ch <= '9') {
            pushData(S, ch - '0');
        }
    }
}
