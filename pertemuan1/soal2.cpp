#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka (1-999): ";
    cin >> n;

    string kata[] = {"", "satu", "dua", "tiga", "empat", "lima","enam", "tujuh", "delapan", "sembilan"};

    string hasil = "";

    if (n >= 100) {
        hasil += (n / 100 == 1 ? "seratus" : kata[n / 100] + " ratus");
        n %= 100;
        if (n) hasil += " ";
    }

    if (n >= 20) {
        hasil += kata[n / 10] + " puluh";
        n %= 10;
        if (n) hasil += " ";
    } else if (n >= 10) {
        if (n == 10) hasil += "sepuluh";
        else if (n == 11) hasil += "sebelas";
        else hasil += kata[n % 10] + " belas";
        n = 0;
    }

    if (n > 0) hasil += kata[n];

    cout << hasil << endl;
    return 0;
}
