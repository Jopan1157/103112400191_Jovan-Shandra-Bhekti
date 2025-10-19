#include "singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, P1);
    deleteLast(L,P5);

    address P;
    deleteAfter(L, P4, P);
    dealokasi(P);
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "- List berhasil terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}