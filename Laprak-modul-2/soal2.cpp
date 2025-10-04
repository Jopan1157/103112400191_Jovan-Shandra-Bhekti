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