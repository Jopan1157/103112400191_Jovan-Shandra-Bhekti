#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteLast() {
        if (tail == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void viewDepan() {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* temp = nullptr;
        Node* current = head;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void menu() {
        int choice, value;
        do {
            cout << "Menu: 1 insert (end), 2 delete (last), 3 view depan, 4 reverse & view depan, 0 exit" << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Masukkan nilai: ";
                    cin >> value;
                    insertEnd(value);
                    break;
                case 2:
                    deleteLast();
                    break;
                case 3:
                    viewDepan();
                    break;
                case 4:
                    reverse();
                    cout << "List setelah di-reverse: ";
                    viewDepan();
                    break;
                case 0:
                    cout << "Keluar..." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    DoublyLinkedList list;
    list.menu();
    return 0;
}
