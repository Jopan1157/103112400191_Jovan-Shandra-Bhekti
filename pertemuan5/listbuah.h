#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool  isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi (string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist list, address node);
void insertafter(linkedlist list, address nodebaru, address prev);
void insertLast(linkedlist list, address nodebaru);
void delfirst (linkedlist list);
void delast (linkedlist list);
void delafter (linkedlist list, address nodehapus, address prev);
int nblist(linkedlist list);
void deletelist(linkedlist &list);

void updatefirst (linkedlist list);
void updatelast (linkedlist list);
void updateafter (linkedlist list, address prev);

#endif