# <h1 align="center">Laporan Praktikum Modul 5 - Singly linked list (bagian 2)</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori

Program ini berfungsi untuk melakukan pencarian data pada struktur data linked list menggunakan bahasa C++. Linked list merupakan kumpulan elemen data yang saling terhubung melalui pointer, di mana setiap node terdiri atas dua bagian, yaitu data dan penunjuk ke node berikutnya. Struktur ini bersifat dinamis dan efisien dalam penambahan maupun penghapusan data tanpa perlu menggeser elemen seperti pada array [1].

Dalam program ini diterapkan dua metode pencarian, yaitu linear search dan binary search. Linear search bekerja dengan menelusuri setiap node satu per satu hingga menemukan data yang sesuai, sedangkan binary search membagi data menjadi dua bagian dan mencari pada sisi tertentu berdasarkan nilai yang dicari. Meskipun binary search lebih cepat pada struktur data berindeks seperti array, pada linked list metode ini kurang efisien karena tidak dapat mengakses elemen tengah secara langsung. Oleh karena itu, linear search lebih sesuai digunakan pada linked list karena karakteristiknya yang sekuensial [2].

### A. Binary

Binary Search adalah algoritma pencarian yang bekerja dengan memecah data yang sudah terurut secara berulang menjadi dua bagian hingga elemen yang dicari ditemukan.                                                                                

### B. Linear

Linear Search merupakan algoritma pencarian sederhana yang bekerja dengan memeriksa setiap elemen secara berurutan dari awal hingga akhir.

## Guided 

### 1. 

listbuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
listbuah.h

```C++
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
```
main.cpp

```C++
#include "listBuah.h"

#include <iostream>
using namespace std;
int main() {
    linkedlist list ;
    address nodeA,nodeB,nodeC,nodeD,nodeE=Nil;
    createList(list);
    
    dataBuah dibuah;

    nodeA = alokasi ("jeruk",100,3000);
    nodeB = alokasi ("apel",75,4000);
    nodeC = alokasi ("pir",87,5000);
    nodeD = alokasi ("semangka",43,11500);
    nodeE = alokasi ("durian",15,31450);

    insertFirst(list,nodeA);
    insertLast(list,nodeB);
    insertafter(list,nodeC,nodeA);
    insertafter(list,nodeD,nodeC);
    insertLast(list,nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(list);
    cout << "Jumlah Node : " << nblist(list) << endl;
    cout << endl;

    updatefirst(list);
    updatelast(list);
    updateafter(list,nodeD);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(list);
    cout << "Jumlah Node : " << nblist(list) << endl;
    cout << endl;

    return 0;
}
```
Program di atas berfungsi untuk mengelola data buah menggunakan struktur data singly linked list dalam bahasa C++. Program ini memungkinkan pengguna untuk melakukan berbagai operasi pada daftar buah, seperti menambahkan (insert), menghapus (delete) memperbarui (update), menampilkan (print), serta menghitung jumlah node (nblist) dalam linked list.

### 2. 

binary

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
Linear

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
Program ini berfungsi untuk mencari data tertentu di dalam struktur data linked list. Pada program pertama, pencarian dilakukan dengan metode binary search, sedangkan pada program kedua menggunakan metode linear search. Keduanya bertujuan untuk menemukan apakah suatu nilai (key) ada dalam linked list dan menampilkan hasil berupa “Found” atau “Not Found”.



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

Program di atas berfungsi untuk mencari data tertentu dalam struktur data linked list menggunakan metode binary search yang diimplementasikan dengan bahasa C++. Program terlebih dahulu membentuk linked list yang berisi data integer terurut, kemudian melakukan pencarian nilai berdasarkan pembagian posisi tengah (mid node) secara berulang hingga data ditemukan atau tidak ditemukan.

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


Program ini berfungsi untuk mencari data tertentu dalam struktur data daftar terkait menggunakan metode pencarian linear dalam bahasa C++. Program ini membuat daftar terkait dari beberapa data integer, menampilkan isi daftar, dan kemudian melakukan pencarian nilai yang dipilih oleh pengguna. Untuk menyelesaikan pencarian, setiap node diselusuri dari awal daftar hingga akhir sampai data yang dicari ditemukan atau seluruh node diperiksa.

## Kesimpulan

Hasil praktikum menunjukkan bahwa Singly Linked List adalah struktur data yang dapat disesuaikan dan efektif untuk mengelola data. Sementara Algoritma Pencarian Linear melakukan pencarian secara berurutan melalui setiap node, Algoritma Pencarian Binar bekerja lebih cepat pada data terurut karena prinsipnya adalah pembagian dua bagian pencarian. Meskipun keduanya memiliki mekanisme kerja yang berbeda, keduanya masih memiliki peran yang signifikan dalam penerapan algoritma pencarian pada struktur data.

## Referensi

[1] Munir, R. (2013). Algoritma dan Pemrograman dalam Bahasa C dan C++. Informatika Bandung. </br>
[2] Siregar, R., & Harahap, D. (2021). Analisis Algoritma Searching pada Struktur Data Linked List Menggunakan Bahasa C++. Jurnal Teknologi dan Sistem Informasi, 9(2), 45–52.