#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Angka di luar jangkauan!" << endl;
        return 0;
    }

    string kata[] = {"", "satu", "dua", "tiga", "empat", "lima",
                     "enam", "tujuh", "delapan", "sembilan"};

    string hasil = "";

    if (n == 0) {
        hasil = "nol";
    } 
    else if (n == 100) {
        hasil = "seratus";
    } 
    else if (n >= 20) {
        hasil += kata[n / 10] + " puluh";
        if (n % 10 != 0) hasil += " " + kata[n % 10];
    } 
    else if (n >= 12) {
        hasil += kata[n % 10] + " belas";
    } 
    else if (n == 11) {
        hasil = "sebelas";
    } 
    else if (n == 10) {
        hasil = "sepuluh";
    } 
    else {
        hasil = kata[n];
    }

    cout << hasil << endl;
    return 0;
}
