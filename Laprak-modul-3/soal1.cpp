#include <iostream>
using namespace std;

// Fungsi untuk menghitung nilai akhir mahasiswa
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
