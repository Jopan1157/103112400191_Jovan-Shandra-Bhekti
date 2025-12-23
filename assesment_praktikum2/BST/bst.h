#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

extern Node* root;

bool isEmpty();
void createTree();
Node* newNode(string nama, float berat, string tier);
Node* insertNode(Node* current, string nama, float berat, string tier);
void inOrder(Node* current);
void mostLeft();
void mostRight();
void searchByBeratBadan(float berat);

#endif
