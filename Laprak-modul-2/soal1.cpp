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