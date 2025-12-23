#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q, infotype &x);
void printInfo(Queue Q);

#endif