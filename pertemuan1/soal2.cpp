#include <iostream>
using namespace std;

string satuan[]  = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

int main() {
    int n;
    cout << "Masukkan angka (1-100): ";
    cin >> n;

    string hasil = "";

    if (n >= 100) {
        hasil += (n/100 == 1 ? "seratus" : satuan[n/100] + " ratus");
        n %= 100;
        if (n) hasil += " ";
    }

    if (n >= 20) {
        hasil += puluhan[n/10];
        n %= 10;
        if (n) hasil += " ";
    } 
    else if (n >= 10) {
        hasil += belasan[n-10];
        n = 0;
    }

    if (n > 0) hasil += satuan[n];

    cout << hasil << endl;
    return 0;
}
