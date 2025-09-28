# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori
Salah satu bahasa tingkat tinggi yang banyak digunakan adalah C++, yang dikembangkan oleh Bjarne Stroustrup sebagai pengembangan dari bahasa C dengan menambahkan konsep kelas (C with Classes). C++ telah berevolusi melalui berbagai standar, seperti C++98, C++11, C++14, hingga C++20, dan tetap menjadi bahasa yang relevan untuk berbagai aplikasi. Keunggulan C++ terletak pada kemampuannya menggabungkan pemrograman prosedural dan berorientasi objek, serta pengendalian langsung terhadap memori. Hal ini membuat C++ banyak digunakan dalam pengembangan perangkat lunak sistem, aplikasi yang membutuhkan performa tinggi, serta bidang teknik yang memerlukan pengolahan data yang kompleks.[1] 

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Operator Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1,angka2 ;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl ;
    cout << "pengurangan :" << angka1 - angka2 << endl ;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" <<  angka1 / angka2 << endl;
}
```
guided 1 menjelaskan bagaimana cara membuat operasi aritmatika di C++

### 2. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1,angka2 ;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

if (angka1 < angka2){
    cout << angka1 << "kurang dari " << angka2 << endl;
}else {
    cout << angka1 << "lebih dari" << angka2 << endl;
}

if (angka1 == angka2) {
    cout << angka1 << "sama dengan" << angka2 << endl;
}else if (angka1 != angka2) {
    cout << "angka berbeda" << endl;
}

int pilihan ;
cout << "menu" << endl;
cout << "1. pengjumlahan" << endl;
cout << "2. pengurangan " << endl;
cout << "masukan pilihan: " << endl;
cin >> pilihan ;

switch (pilihan) {
    case 1 :
    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << endl;
    break;
    case 2 :
    cout << "pengurangan : " << angka1 + angka2 << endl;
    cout << endl;
    break;
    default :
    cout << "pilihan salah" << endl;
}
    return 0;
}

```
program ini menjelaskan contoh percabangan (if, if-else) dan switch-case serta operasi aritmatika sederhana (penjumlahan/pengurangan)

### 3. Perulangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukan angka 1 :";
    cin >> angka1;

    for (int i = 0; i < angka1; i++) {
        cout << i << "-"; 
    }
    cout << endl;
    int j = 10;
    while (j > angka1){
        cout << j << "-";
        j--;
    }
    cout << endl;
    int k = 10;
    do {
        cout << k << "-";
    } while (k < angka1);

    return 0 ;
}
```
program ini mencontohkan tiga jenis perulangan (for, while, do while) dengan pola cetak angka berbeda.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float A, B ;
    cout << "masukan angka 1: ";
    cin >> A;
    cout << "masukan angka 2: ";
    cin >> B;

    cout << "penjumlahan :" << (A + B) << endl ;
    cout << "pengurangan :" << (A - B) << endl ;
    cout << "perkalian :" << (A * B) << endl;
    cout << "pembagian :" <<  (A / B) << endl;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/pertemuan1/ss-soal-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)
 
Program ini berfungsi menghitung operasi aritmatika dari dua bilangan bertipe data float yang di masukan user

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100


```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Suryanto, D. (2023). Penggunaan bahasa C++ dalam perkuliahan jurusan Teknik Elektro Fakultas Teknik. Jurnal Majemuk, 9(2), 45–53.
<br>...
