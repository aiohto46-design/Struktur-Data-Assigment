#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    infotype x;

    cout << "Hello world!" << endl;
    cout << "---" << endl;
    cout << "H - T    Queue Info" << endl;
    cout << "---" << endl;
    
    CreateQueue(Q);
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q, x); printInfo(Q);
    dequeue(Q, x); printInfo(Q);
    dequeue(Q, x); printInfo(Q);

    return 0;
}