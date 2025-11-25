#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa StackMHS;
    createStack(StackMHS);

    Mahasiswa mhs1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa mhs2 = {"Xiao","22222", 87.4,88.9,81.9};
    Mahasiswa mhs3 = {"Kazuha","33333",92.3,88.8,82.4};
    Mahasiswa mhs4 = {"Wanderer","44444",95.5,85.5,90.5};
    Mahasiswa mhs5 = {"Lynette","55555",77.7,65.4,79.9};
    Mahasiswa mhs6 = {"Chasca", "66666",99.9,93.6,87.3};

    Push(StackMHS, mhs1);
    Push(StackMHS, mhs2);
    Push(StackMHS, mhs3);
    Push(StackMHS, mhs4);
    Push(StackMHS, mhs5);
    Push(StackMHS, mhs6);
    cout << "Data Mahasiswa dalam Stack:" << endl;
    View(StackMHS);

    cout << "\nLakukan Pop 1x" << endl;
    Pop(StackMHS);
    View(StackMHS);

    Mahasiswa mhsUpdate = {"Heizou", "77777",99.9,88.8,77.7};
    Update(StackMHS, 3, mhsUpdate);
    
    View(StackMHS);
    cout << "\nSearching data mahasiswa dengan nilai akhir antara 85.5 dan 95.5:" << endl;
    SearchNilaiAkhir(StackMHS, 85.5, 95.5);

    cout << "\nMencari mahasiswa dengan nilai akhir terbesar:" << endl;
    MaxNilaiAkhir (StackMHS);

    return 0;

}