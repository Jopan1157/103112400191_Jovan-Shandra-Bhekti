# <h1 align="center">Laporan Praktikum Modul 2 - Array & Pointer Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori
Menurut Suryanto (2023), C++ merupakan salah satu bahasa pemrograman yang banyak digunakan dalam dunia akademik maupun praktis karena mendukung pemrograman prosedural maupun berorientasi objek. Dalam penggunaannya, terdapat berbagai konsep dasar yang penting dipahami, di antaranya array dan pointer. Array adalah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe yang sama dalam satu variabel. Setiap elemen array dapat diakses melalui indeks yang dimulai dari 0 hingga ukuran array dikurangi satu. Array mempermudah penyimpanan dan pengolahan banyak data dengan tipe yang sama, sehingga mereka efektif dalam penggunaan memori dan pemanggilan data.Pointer adalah variabel unik yang menyimpan alamat memori untuk variabel lain. Dengan menggunakan alamat yang ditunjuk, program dapat mengakses dan mengubah data secara tidak langsung. Karena nama array sebenarnya mewakili alamat elemen pertama dalam array, pointer sangat penting untuk mengelola array. Oleh karena itu, elemen dapat diakses melalui aritmatika pointer dan indeks, yang keduanya memberikan hasil yang sama.[1]

### A. Array <br/>

Array di C++ adalah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe yang sama dalam satu variabel. Data diakses melalui indeks (dimulai dari 0), tersimpan berurutan di memori, dan memiliki ukuran tetap

### B. Pointer <br/>

Pointer di C++ adalah variabel khusus yang menyimpan alamat memori dari suatu variabel lain. Dengan pointer, kita bisa mengakses dan memanipulasi data secara tidak langsung melalui alamat memori.

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j=0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini berfungsi untuk menerima 5 angka dari user, lalu menampilkannya kembali sesuai urutan indeks array.

### 2. Array Pointer

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i<5; ++i){
        cout << " Elemen array ke-" << i+1 << " menggunakan pointer : " << *(ptr + i) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}

```
Program ini berfungsi untuk menampilkan isi array dengan dua cara, yaitu menggunakan pointer (melalui aritmatika alamat memori) dan menggunakan indeks secara langsung, sehingga menunjukkan bahwa kedua cara tersebut memberikan hasil yang sama.

### 3. Fungsi Prosedur

```C++
#include <iostream>
using namespace std;

int cariMAX (int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i ++){
        totaljumlah += arr[i];
    }
    cout << " total penjumlahan : " << totaljumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }

    cout << " total perkalian : " << totalKali << endl;
}
    int main (){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "masukan nilai arrray ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran)<< endl;

    operasiAritmatika(arr, ukuran);
    return 0;

}

```
Program ini berfungsi untuk menginput data ke dalam array, mencari nilai terbesar dari data tersebut, serta menghitung total penjumlahan dan total perkalian dari seluruh elemen array dengan memanfaatkan fungsi, perulangan, dan operasi aritmatika dalam bahasa C++.

## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini :
matriksA = 
[7 12 22
31 6 41
15 19 36]
MatriksB = 
[11 34 7
3 25 41
5 18 33]
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan;
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case
seperti berikut ini :
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar


```C++
#include <iostream>
using namespace std;

void jumlahMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}


void kurangMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}


void kaliMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void tampilMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "[ ";
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j];
            if (j < 2) cout << "\t";
        }
        cout << " ]" << endl;
    }
}

int main() {
    int matriksA[3][3] = {{7, 12, 22}, {31, 6, 41}, {15, 19, 36}};
    int matriksB[3][3] = {{11, 34, 7}, {3, 25, 41}, {5, 18, 33}};
    int hasil[3][3];

    int pilihan;
    do {
        cout << "\n Menu Program Matriks \n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            jumlahMatriks(matriksA, matriksB, hasil);
            cout << "Hasil Penjumlahan Matriks:\n";
            tampilMatriks(hasil);
            break;
        case 2:
            kurangMatriks(matriksA, matriksB, hasil);
            cout << "Hasil Pengurangan Matriks:\n";
            tampilMatriks(hasil);
            break;
        case 3:
            kaliMatriks(matriksA, matriksB, hasil);
            cout << "Hasil Perkalian Matriks:\n";
            tampilMatriks(hasil);
            break;
        case 4:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-2/ss-jwb-no1.png)

Program ini mendemonstrasikan penggunaan array 2 dimensi dan fungsi prosedural untuk melakukan berbagai operasi dasar matriks.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan
dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.


```C++

#include <iostream>
using namespace std;

int main() {
    int panjang = 10;
    int lebar = 5;
    int luas = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "Nilai awal : " << endl;
    cout << "panjang : " << panjang << endl;
    cout << "lebar : " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);

    cout << "Hasil Perhitungan :" << endl;
    cout << "luas Persegi panjang : " << luas << endl;
    cout << "Keliling persegi panjang = " << 2 * ((*ptrPanjang) + (*ptrLebar)) << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    
    cout << "Nilai setelah di ubah melalui pointer :" << endl;
    cout << "Panjang baru : " << panjang << endl;
    cout << "Lebar baru : " << lebar << endl;
    cout << "Luas baru : " << luas << endl;
    cout << "Keliling baru = " << 2 * ((*ptrPanjang) + (*ptrLebar)) << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-2/ss-jwb-no2.png)


Program tersebut berfungsi untuk menghitung luas dan keliling persegi panjang menggunakan pointer.


## Kesimpulan
dalam praktikum modul 1 ini mempelajari dasar penggunaan C++ seperti operator aritmatika,percabangan(if-else, switch-case),perulangan(for,while,do-while),selain itu, terdapat latihan unguided yang memberikan pengalaman seperti mengimplementasikan operasi aritmatika menggunakan tipe data float, mengubah angka menjadi bentuk kata, serta membuat pola dengan kombinasi angka dan simbol.

## Referensi
[1] Suryanto, D. (2023). Penggunaan bahasa C++ dalam perkuliahan jurusan Teknik Elektro Fakultas Teknik. Jurnal Majemuk, 9(2), 45–53.
<br>...
