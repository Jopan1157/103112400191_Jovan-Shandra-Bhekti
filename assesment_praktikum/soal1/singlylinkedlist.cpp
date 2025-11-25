#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(string name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteName(string name) {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Nama tidak ditemukan." << endl;
        } else {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        }
    }

    void view() {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void hitungGenap() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name.length() % 2 == 0) {
                count++;
            }
            temp = temp->next;
        }
        cout << "Jumlah nama dengan huruf genap: " << count << endl;
    }

    void menu() {
        int choice;
        string name;

        do {
            cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Masukkan nama: ";
                    cin >> name;
                    insert(name);
                    break;
                case 2:
                    cout << "Masukkan nama untuk delete: ";
                    cin >> name;
                    deleteName(name);
                    break;
                case 3:
                    view();
                    break;
                case 4:
                    hitungGenap();
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
    SinglyLinkedList list;
    list.menu();
    return 0;
}
