#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; 
    if (!head) {
        head = newNode; 
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next; 
        temp->next = newNode;                
    }
}


void displayList(Node* head) {
    cout << "Linked List yang dibuat: "; 
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";  
}

Node* linearSearch(Node* head, int key) {
    cout << "\nMencari nilai: " << key << "\n"; 
    cout << "\nProses Pencarian:\n"; 

    Node* current = head;
    int step = 1;

    while (current != nullptr) {
        cout << "Memeriksa node " << step << ": " << current->data; 

        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n"; 
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n"; // Ditambah newline
            cout << "Alamat node: " << current << "\n"; 
            cout << "Data node: " << current->data << "\n";
            if (current->next)
                cout << "Node berikutnya: " << current->next->data << "\n"; 
            else
                cout << "Node berikutnya: NULL\n";
            return current;
        } else {
            cout << " (tidak sama)\n"; 
        }

        current = current->next;
        ++step;
    }

    cout << "Tidak ada node lagi yang tersisa\n"; 
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n"; 
    return nullptr;
}

int main() {
    cout << "# LINEAR SEARCH PADA LINKED LIST\n"; 
    
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40); 
    append(head, 50);

    displayList(head); 

    linearSearch(head, 30);
    linearSearch(head, 25);

    return 0;
}