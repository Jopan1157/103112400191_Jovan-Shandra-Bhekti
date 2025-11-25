#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);  
    int pilihan;
    while (true) {
        cout << "--- Komaniya Ekspres ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                enqueue(Q); 
                break;
            case 2:
                dequeue(Q);  
                break;
            case 3:
                viewQueue(Q);  
                break;
            case 4:
                TotalBiayaPengiriman(Q);  
                break;
            case 0:
                return 0;  
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}