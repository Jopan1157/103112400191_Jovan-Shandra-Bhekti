#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MaxEl 5     
#define Nil -1      

typedef int infotype;

struct Queue {
    infotype info[MaxEl];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
