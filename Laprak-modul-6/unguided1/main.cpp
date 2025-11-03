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
