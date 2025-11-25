#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;  

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];  
    int Head;              
    int Tail;             
};

bool isEmpty(QueueEkspedisi &Q);
bool isFull(QueueEkspedisi &Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q);
void dequeue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi &Q);
void TotalBiayaPengiriman(QueueEkspedisi &Q);

#endif