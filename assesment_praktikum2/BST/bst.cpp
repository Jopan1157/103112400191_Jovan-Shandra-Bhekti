#include "bst.h"

Node* root;

bool isEmpty() {
    return root == NULL;
}

void createTree() {
    root = NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node;
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* current, string nama, float berat, string tier) {
    if (current == NULL) {
        return newNode(nama, berat, tier);
    }
    if (berat < current->beratBadan) {
        current->left = insertNode(current->left, nama, berat, tier);
    } else if (berat > current->beratBadan) {
        current->right = insertNode(current->right, nama, berat, tier);
    }
    return current;
}

void inOrder(Node* current) {
    if (current != NULL) {
        inOrder(current->left);
        cout << current->beratBadan << " - ";
        inOrder(current->right);
    }
}

void mostLeft() {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    cout << "Node MostLeft : " << current->beratBadan << endl;
}

void mostRight() {
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    cout << "Node MostRight : " << current->beratBadan << endl;
}

void searchByBeratBadan(float berat) {
    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        if (berat == current->beratBadan) {
            cout << "Data ditemukan didalam BST!\n";
            cout << "--- Data Node Yang Dicari ---\n";
            cout << "Nama Member : " << current->namaMember << endl;
            cout << "Berat Badan : " << current->beratBadan << endl;
            cout << "Tier Member : " << current->tierMember << endl;
            cout << "-----------------------------\n";

            if (parent != NULL) {
                cout << "--- Data Parent ---\n";
                cout << "Nama Member : " << parent->namaMember << endl;
                cout << "Berat Badan : " << parent->beratBadan << endl;
                cout << "Tier Member : " << parent->tierMember << endl;
            }

            cout << "-----------------------------\n";
            cout << "Tidak Memiliki Sibling\n";
            cout << "-----------------------------\n";

            if (current->left != NULL) {
                cout << "--- Data Child Kiri ---\n";
                cout << "Nama Member : " << current->left->namaMember << endl;
                cout << "Berat Badan : " << current->left->beratBadan << endl;
                cout << "Tier Member : " << current->left->tierMember << endl;
            }

            cout << "-----------------------------\n";

            if (current->right != NULL) {
                cout << "--- Data Child Kanan ---\n";
                cout << "Nama Member : " << current->right->namaMember << endl;
                cout << "Berat Badan : " << current->right->beratBadan << endl;
                cout << "Tier Member : " << current->right->tierMember << endl;
            }

            cout << "-----------------------------\n";
            return;
        }

        parent = current;
        if (berat < current->beratBadan)
            current = current->left;
        else
            current = current->right;
    }

    cout << "Data tidak ditemukan\n";
}


