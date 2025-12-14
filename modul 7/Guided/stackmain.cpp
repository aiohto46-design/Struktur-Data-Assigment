// soal 1
#include "Stack.h"

int main() {
    cout << "Hello world!" << endl;
    
    Stack S;
    init(S);

    pushData(S, 5);
    pushData(S, 1);
    pushData(S, 7);
    pushData(S, 3);

    tampil(S);

    cout << "Setelah dibalik:" << endl;
    reverse(S);
    tampil(S);

    return 0;
}


// soal 2
// #include "stack.h"

// int main() {
//     cout << "Hello world!" << endl;

//     Stack S;
//     init(S);

//     pushUrut(S, 4);
//     pushUrut(S, 2);
//     pushUrut(S, 9);
//     pushUrut(S, 1);
//     pushUrut(S, 6);

//     tampil(S);

//     cout << "Setelah dibalik:" << endl;
//     reverse(S);
//     tampil(S);

//     return 0;
// }


// soal 3
// #include "stack.h"

// int main() {
//     cout << "Hello world!" << endl;

//     Stack S;
//     init(S);

//     cout << "Masukkan angka (tanpa spasi): ";
//     bacaInput(S);

//     tampil(S);

//     cout << "Setelah dibalik:" << endl;
//     reverse(S);
//     tampil(S);

//     return 0;
// }
