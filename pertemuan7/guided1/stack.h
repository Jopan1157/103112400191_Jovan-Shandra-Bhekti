#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};
struct stack {
    address top;
};

bool isEmpty(stack liststack);
void createStack(stack &liststack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &liststack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);
#endif