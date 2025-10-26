# <h1 align="center">Laporan Praktikum Modul 5 - Singly linked list (bagian 2)</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori
Singly Linked List atau senarai berantai tunggal merupakan salah satu bentuk struktur data dinamis yang banyak digunakan dalam pemrograman komputer, khususnya pada bahasa C++. Menurut Annafi Franz (2020) dalam buku Struktur Data dengan C++, singly linked list terdiri dari kumpulan elemen yang disebut node, di mana setiap node memiliki dua komponen utama, yaitu data yang menyimpan nilai atau informasi, dan pointer (next) yang menunjuk ke node berikutnya dalam daftar.[1] Dalam implementasinya di bahasa C++, singly linked list biasanya dibangun menggunakan struct untuk mendefinisikan node, dengan pointer sebagai penghubung antar-node. Operasi dasar yang dapat dilakukan meliputi penambahan node (insert), penghapusan node (delete), serta penelusuran (traversal) untuk melihat isi daftar. Meskipun memiliki kelemahan dalam hal akses acak karena tidak dapat langsung menuju node tertentu, singly linked list tetap menjadi salah satu struktur data yang penting untuk memahami konsep manajemen memori dan pointer dalam pemrograman C++.[2]

### A. Binary

Binary Search adalah algoritma pencarian yang bekerja dengan membagi data menjadi dua bagian secara berulang dan hanya mencari di bagian yang relevan. Namun, implementasinya pada linked list memiliki tantangan khusus.

### B. Linear

Linear Search merupakan algoritma pencarian sederhana yang bekerja dengan memeriksa setiap elemen secara berurutan dari awal hingga akhir.

## Guided 

### 1. linear

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program di atas berfungsi untuk membuat, menambah, dan mencari data dalam sebuah Linked List secara linear (linear search)..

### 2. binary 

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* & head, int value) {
    Node* newNode = new Node {value,nullptr};
    
    if(!head) head = newNode;

    else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current -> next) size++;
    Node *start = head;
    Node *end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        for (int i = 0; i < mid; i++) {
            midNode = midNode -> next;
        }

        if (midNode -> data == key ) return midNode;
        if (midNode -> data < key) {
            start = midNode -> next;
    }
    else {
        end = midNode;
    }
    size -= mid;
}
return nullptr;
}
int main(){
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program di atas berfungsi untuk membuat linked list dan melakukan pencarian data menggunakan metode binary search pada linked list.



## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary
Search pada Linked List untuk mencari elemen tertentu. Program
harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 1:
• Gunakan struktur Node dengan data integer dan pointer next
• Implementasikan fungsi append() untuk menambah node
• Implementasikan fungsi binarySearch() yang mengembalikan
pointer ke node yang ditemukan
• Data dalam linked list harus terurut (ascending) untuk
binary search bekerja dengan benar
• Tampilkan langkah-langkah pencarian dan posisi tengah
setiap iterasi
• Program utama harus membuat linked list dengan minimal 5
elemen dan melakukan pencarian

```C++
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next; 
};

void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
      
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
 
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
           
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            size = mid;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    displayList(head);
    
    cout << "Mencari nilai: 40";
    
    Node* result = binarySearch(head, 40);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 40 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    cout << "Mencari nilai: 25";
    
    result = binarySearch(head, 25);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    deleteList(head);
    
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-5/ss-jwb-no1.png)

Program ini berfungsi .........

### 2. Implementasikan program C++ yang menggunakan algoritma Linear
Search pada Linked List untuk mencari elemen tertentu. Program
harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 2:
• Gunakan struktur Node dengan data integer dan pointer next
• Implementasikan fungsi append() untuk menambah node
• Implementasikan fungsi linearSearch() yang mengembalikan
pointer ke node yang ditemukan
• Data dalam linked list tidak perlu terurut untuk linear
search
• Tampilkan setiap langkah pencarian dan node yang sedang
diperiksa
• Program utama harus membuat linked list dengan minimal 3
elemen dan melakukan pencarian


```C++

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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-5/ss-jwb-no2.png)


Program ini berfungsi .......

## Kesimpulan
Hasil praktikum Modul 4 tentang Singly Linked List menunjukkan bahwa struktur data ini adalah salah satu jenis struktur data dinamis yang terdiri dari elemen yang terhubung melalui pointer. Setiap node atau elemen terdiri dari dua komponen: data (yang berfungsi untuk menyimpan nilai atau informasi) dan pointer next (yang berfungsi sebagai penunjuk ke node berikutnya).
## Referensi
[1] Franz, A. (2020). Struktur Data dengan C++. Samarinda: Politeknik Negeri Samarinda Press. ISBN 978-623-5771-03-8.
[2] Ramadhani, C. (2021). Algoritma Pemrograman dan Struktur Data Menggunakan C++. Denpasar: Primakara University Press.
<br>...
