#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi &Q) {
    return Q.Head == -1;
}
bool isFull(QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}
void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}
void enqueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    Paket p;
    cout << "Masukkan Kode Resi: ";
    cin >> p.KodeResi;
    cout << "Masukkan Nama Pengirim: ";
    cin >> p.NamaPengirim;
    cout << "Masukkan Berat Barang (kg): ";
    cin >> p.BeratBarang;
    cout << "Masukkan Tujuan: ";
    cin >> p.Tujuan;

    if (Q.Head == -1) {
        Q.Head = 0; 
    }
    Q.Tail++;  
    Q.dataPaket[Q.Tail] = p;
}
void dequeue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    for (int i = 0; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }
    Q.Tail--;
    if (Q.Tail == -1) {
        Q.Head = -1;
    }
}
void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Kode Resi: " << Q.dataPaket[i].KodeResi << endl;
        cout << "Nama Pengirim: " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "Berat Barang: " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << "Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        cout << "---------------------------------" << endl;
    }
}
void TotalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong, tidak ada paket untuk dihitung!" << endl;
        return;
    }
    int totalBiaya = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBiaya += Q.dataPaket[i].BeratBarang * 8250;  
    }
    cout << "Total biaya pengiriman semua paket: Rp " << totalBiaya << endl;
}