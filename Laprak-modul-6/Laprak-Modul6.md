# <h1 align="center">Laporan Praktikum Modul 6 - Double linked list (bagian 1)</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori

Struktur data doubly linked list (DLL) adalah jenis linked list yang setiap elemennya memiliki dua pointer: satu menunjuk ke elemen berikutnya dan satu lagi ke elemen sebelumnya. Dengan dua arah ini, data bisa ditelusuri maju maupun mundur, membuatnya lebih fleksibel dibandingkan singly linked list yang hanya satu arah. Keunggulannya, operasi seperti menambah atau menghapus data di tengah list bisa dilakukan lebih mudah tanpa harus menelusuri dari awal. Operasi utama pada DLL meliputi penambahan data (insert), penghapusan data (delete), pencarian data (search), dan pengecekan keberadaan data.[1]

### A. insert

insert pada doubly linked list adalah proses menambahkan elemen baru ke dalam list yang setiap elemennya memiliki dua pointer — satu menunjuk ke elemen sebelumnya (prev) dan satu ke elemen berikutnya (next).
Insert First → elemen baru ditambahkan di awal list, menjadi elemen pertama.

Insert Last → elemen baru ditambahkan di akhir list, menjadi elemen terakhir.

Insert After / Before → elemen baru disisipkan di antara dua elemen yang sudah ada.

### B. delete

Delete First
Menghapus elemen pertama dari list. Pointer first akan dipindahkan ke elemen berikutnya, dan pointer prev pada elemen baru pertama diatur menjadi Nil.

Delete Last
Menghapus elemen terakhir dari list. Pointer last akan dipindahkan ke elemen sebelumnya, dan pointer next pada elemen baru terakhir diatur menjadi Nil.

Delete After
Menghapus elemen yang berada setelah node tertentu. Pointer next dari node sebelumnya dihubungkan ke node setelah elemen yang dihapus, dan pointer prev dari node setelahnya juga disesuaikan.

Delete Before
Menghapus elemen yang berada sebelum node tertentu. Pointer prev dari node berikutnya dihubungkan ke node sebelum elemen yang dihapus, dan pointer next dari node sebelumnya disesuaikan.

## Guided 

### 1. 

listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
listMakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
program ini merupakan implementasi dari manipulasi data makanan (nama, jenis, harga, dan rating) dalam bentuk struktur data double linked list yang mendukung operasi insert, update, dan tampil data secara dinamis.

### 2. 

Doublylist.cpp

```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif
```

main.cpp

```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program ini berfungsi untuk mengelola data kendaraan menggunakan struktur data doubly linked list (daftar berantai ganda).



## Unguided 

### 1.  Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:
Type infotype : kendaraan <
nopol : string
warna : string
thnBuat : integer
>
Type address : pointer to ElmList
Type ElmList <
info : infotype
next :address
prev : address
>
Type List <
First : address
Last : address
>
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertLast(input/output L : List,
input P : address )
Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil
implementasi ADT pada file “main.cpp”

doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address prev, address &p);
bool cekList(List L, string nopol);
void printInfo(List L);

#endif
```

doublylist.cpp

```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return Nil;
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = L.first->next;
    P->prev = Nil;
    L.first->prev = Nil;
    P->next = Nil;
    dealokasi(P);
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last->prev;
    P->next = Nil;
    L.last->next = Nil;
    dealokasi(P);
}

void deleteAfter(address prev, address &P) {
    if (prev != NULL && prev->next != NULL) {
        P = prev->next;
        prev->next = P->next;
        if (P->next != NULL) P->next->prev = prev;
        P->next = NULL;
        P->prev = NULL;
        dealokasi(P);
    }
}

bool cekList(List L, string nopol) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q->info.nopol == nopol) return true;
        Q = Q->next;
    }
    return false;
}

```
main.cpp

```C++
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    int n;
    cout << "Masukan banyak data: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;

        if (cekList(L, data.nopol)) {
            cout << "Masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            cout << "Nomor polisi sudah terdaftar\n";
        } else {
            cout << "Masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            P = alokasi(data);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "DATA LIST 1\n";
    printInfo(L);

    string cariNopol = "D001";
    cout << "Masukan Nomor polisi yang dicari: " << cariNopol << endl;
    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi: " << found->info.nopol 
             << "\nWarna: " << found->info.warna 
             << "\nTahun: " << found->info.thnBuat << "\n\n";
    } else {
        cout << cariNopol << " tidak ditemukan.\n\n";
    }

    address prev = L.first;
    while (prev != Nil && prev->next != Nil) {
        if (prev->next->info.nopol == "D003") break;
        prev = prev->next;
    }
    if (prev != Nil && prev->next != Nil) {
        deleteAfter(prev, P);
        cout << "Data dengan nomor polisi D003 berhasil dihapus\n";
    } else {
        cout << "Data dengan nomor polisi D003 tidak ditemukan\n";
    }

    cout << "DATA LIST 1\n";
    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-6/ss-jwb-no1.png)

Program ini berfungsi untuk mengelola informasi kendaraan dengan memanfaatkan struktur data Doubly Linked List (daftar berantai dua arah). Melalui program ini, pengguna dapat melakukan beberapa operasi penting seperti menambahkan data kendaraan di bagian akhir list (insert last), memeriksa apakah nomor polisi sudah ada dalam data, menampilkan seluruh data kendaraan yang tersimpan, mencari kendaraan berdasarkan nomor polisi, serta menghapus data tertentu dengan menggunakan operasi deleteAfter.


## Kesimpulan

Berdasarkan modul ini dapat disimpulkan bahwa struktur data Doubly Linked List sangat bermanfaat untuk manajemen data yang membutuhkan akses dua arah, maju dan mundur. Dengan menggunakan program yang dibuat, pengguna dapat menambah, mencari, menampilkan, dan menghapus data kendaraan dengan lebih efisien. Setiap elemen dalam daftar memiliki pointer next dan prev, yang memungkinkan data dimanipulasi tanpa harus mulai dari awal. Oleh karena itu, Doubly Linked List sangat fleksibel dalam mengelola data dinamis dan merupakan salah satu struktur penting dalam pengembangan sistem yang memerlukan efisiensi dalam operasi penyisipan dan penghapusan data.

## Referensi

[1] Rahmawati, D., & Prasetyo, H. (2021). Penggunaan algoritma doubly linked list untuk insertion dan deletion. Jurnal Riset Informatika Indonesia, 3(2), 45–52.