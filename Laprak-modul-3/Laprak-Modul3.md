# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak merupakan suatu konsep penting dalam pemrograman yang berhubungan dengan cara pengorganisasian dan pengelolaan data. ADT didefinisikan sebagai model matematis dari suatu tipe data yang disertai dengan sekumpulan operasi yang dapat dilakukan terhadap data tersebut, tanpa memperhatikan bagaimana data dan operasi tersebut diimplementasikan secara fisik dalam program [1].
Konsep ADT menekankan pada abstraksi, yaitu pemisahan antara definisi logis dan implementasi konkret. Artinya, pengguna suatu ADT hanya perlu mengetahui fungsi dan cara menggunakan operasi yang disediakan, tanpa harus memahami detail penyimpanan data atau algoritma yang digunakan di dalamnya. Hal ini bertujuan untuk meningkatkan modularitas dan kemudahan pemeliharaan program.

### A. Abstract Data Type (ADT) <br/>

ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam
sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT
merupakan definisi STATIK.


## Guided 

### 1. Struct

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMHS(mahasiswa &m) {
    cout << "masukkan nama mahasiswa:";
    cin >> m.nama;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2)/2;

}

int main() {
    mahasiswa mhs;

    inputMHS(mhs);
    cout << "Rata - rata nilai adalah : " << rata2(mhs) << endl;

    system("pause");
    return 0;
}
```
Program ini berfungsi untuk menginput data seorang mahasiswa berupa nama, nilai pertama, dan nilai kedua, kemudian menghitung serta menampilkan nilai rata-ratanya.

### 2. Single Linked list

```C++
#include <iostream>
using namespace std;

struct node{
    float data;
    node* next;

}; 

struct list{
    node* first;

};

void buatList(list &L){
    L.first = NULL;
    
}

node* buatElemen(float X){
    node* elm = new node;
    elm -> data = X;
    elm -> next = NULL;
    return elm;
}
void insertAscending( list &L, node* elm){
    if (L.first == NULL || elm -> data < L.first -> data ){
        elm -> next = L.first;
        L.first = elm;

    }
    else{
        node* before = L.first;
        node* after = L.first -> next;
        while(after != NULL && elm -> data > after -> data){
            before = after;
            after = after -> next;
        }
        elm -> next = after;
        before -> next = elm;
    }
}

void tampilList(list L){
    node* p = L.first;
    while(p != NULL){
        cout << p -> data << " -> ";
        p = p -> next;
    }
    cout << "NULL " << endl;
}

int main(){
    list L;
    buatList(L);

    node* satu = buatElemen(10.5);
    node* dua = buatElemen(12.0);
    node* tiga =  buatElemen(20.9);
    node* empat = buatElemen(25.1);

    satu -> next = dua;
    dua -> next = tiga;
    tiga -> next = empat;

    L.first = satu;
    
    cout << "isi list : " << endl;
    tampilList(L);

    float X;
    cout << "Masukan nilai : ";
    cin >>  X;

    node* elm = buatElemen(X);
    insertAscending(L, elm );
    cout << "List setelah ditambah : " << endl;
    tampilList(L);
    return 0;
}

```
Program ini mengimplementasikan struktur data linked list satu arah yang berisi data bertipe float, dan menambahkan elemen baru secara ascending berdasarkan nilai.

### 3. 

```C++

```

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.


```C++
#include <iostream>
using namespace std;

float nilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    string nama, nim;
    float uts, uas, tugas;
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : "; cin >> nama;
        cout << "NIM   : "; cin >> nim;
        cout << "Nilai UTS   : "; cin >> uts;
        cout << "Nilai UAS   : "; cin >> uas;
        cout << "Nilai Tugas : "; cin >> tugas;

        float hasil = nilaiAkhir(uts, uas, tugas);
        cout << "Hasil Nilai Akhir: " << hasil << endl;
    }

    return 0;
}



```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-3/ss-jwb-1.png)

Program ini digunakan untuk menginput dan menghitung nilai akhir beberapa mahasiswa berdasarkan nilai UTS, UAS, dan Tugas.

### 2. ![Screenshot Soal Unguided 2](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-3/ss-soal-2.png)


```C++

file pelajaran.h 

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif


file pelajaran.cpp 

#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai  : " << pel.kodeMapel << endl;
}


file main.cpp 

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}


```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-3/ss-jwb-2.png)

### 3.  Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
  pointer



```C++
#include <iostream>
using namespace std;


void tampilArray(int data[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}


void tukarElemen(int a[3][3], int b[3][3], int i, int j) {
    int temp = a[i][j];
    a[i][j] = b[i][j];
    b[i][j] = temp;
}


void tukarPtr(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{4,2,3},{6,3,2},{8,5,9}};
    int B[3][3] = {{9,4,6},{3,1,2},{7,4,4}};
    int x = 10, y = 20;

    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    
    tukarElemen(A, B, 1, 1);

    cout << "\nSetelah tukar elemen (1,1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPtr(&x, &y);
    cout << "Sesudah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-3/ss-jwb-3.png)

Program ini digunakan untuk menampilkan isi dua array 2D berukuran 3×3, kemudian menukar elemen tertentu di posisi yang sama antar dua array, serta menukar nilai dua variabel menggunakan pointer.


## Kesimpulan

Dari hasil praktikum Modul 3 tentang Abstract Data Type (ADT) dapat disimpulkan bahwa ADT merupakan konsep dasar dalam pemrograman yang berfungsi untuk memisahkan antara definisi logis suatu tipe data dan implementasi teknisnya. Dengan adanya ADT, program dapat dibuat lebih modular, terstruktur, dan mudah dipelihara, karena setiap tipe data dan operasinya dikelola dalam satu kesatuan logis yang terpisah dari cara implementasinya.

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
<br>...
