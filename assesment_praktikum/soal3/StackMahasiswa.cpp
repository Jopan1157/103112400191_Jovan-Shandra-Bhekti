#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

bool isEmpty(StackMahasiswa& StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa& StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa& StackMHS) {
    StackMHS.Top = -1;
}

void Push(StackMahasiswa& StackMHS, Mahasiswa data) {
    if (isFull(StackMHS)) {
        cout << "Stack is full!" << endl;
    } else {
        StackMHS.Top++;
        StackMHS.dataMahasiswa[StackMHS.Top] = data;
    }
}

void Pop(StackMahasiswa& StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack is empty!" << endl;
    } else {
        StackMHS.Top--;
    }
}

void Update(StackMahasiswa& StackMHS, int posisi, Mahasiswa data) {
    if (posisi >= 0 && posisi <= StackMHS.Top) {
        StackMHS.dataMahasiswa[posisi] = data;
    } else {
        cout << "Invalid position!" << endl;
    }
}

void View(StackMahasiswa& StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack is empty!" << endl;
    } else {
        for (int i = 0; i <= StackMHS.Top; i++) {
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << ", NIM: " << StackMHS.dataMahasiswa[i].NIM
                 << ", Nilai Tugas: " << StackMHS.dataMahasiswa[i].NilaiTugas << ", Nilai UTS: "
                 << StackMHS.dataMahasiswa[i].NilaiUTS << ", Nilai UAS: " << StackMHS.dataMahasiswa[i].NilaiUAS << endl;
        }
    }
}

void SearchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    for (int i = 0; i <= StackMHS.Top; i++) {
        float NilaiAkhir = 0.2 * StackMHS.dataMahasiswa[i].NilaiTugas + 0.4 * StackMHS.dataMahasiswa[i].NilaiUTS + 0.4 * StackMHS.dataMahasiswa[i].NilaiUAS;
        if (NilaiAkhir >= NilaiAkhirMin && NilaiAkhir <= NilaiAkhirMax) {
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << ", Nilai Akhir: " << NilaiAkhir << endl;
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa& StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack is empty!" << endl;
        return;
    }

    int posisiMax = 0;
    float nilaiMax = 0;

    for (int i = 0; i <= StackMHS.Top; i++) {
        float NilaiAkhir = 0.2 * StackMHS.dataMahasiswa[i].NilaiTugas + 
                            0.4 * StackMHS.dataMahasiswa[i].NilaiUTS + 
                            0.4 * StackMHS.dataMahasiswa[i].NilaiUAS;
        
        if (NilaiAkhir > nilaiMax) {
            nilaiMax = NilaiAkhir;
            posisiMax = i;
        }
    }

    cout << "Mahasiswa dengan Nilai Akhir terbesar adalah: " << endl;
    cout << "Nama: " << StackMHS.dataMahasiswa[posisiMax].Nama 
         << ", NIM: " << StackMHS.dataMahasiswa[posisiMax].NIM 
         << ", Nilai Tugas: " << StackMHS.dataMahasiswa[posisiMax].NilaiTugas 
         << ", Nilai UTS: " << StackMHS.dataMahasiswa[posisiMax].NilaiUTS 
         << ", Nilai UAS: " << StackMHS.dataMahasiswa[posisiMax].NilaiUAS 
         << ", Nilai Akhir: " << nilaiMax << endl;

    cout << "Posisi data berada di posisi ke-" << posisiMax << endl;
}
