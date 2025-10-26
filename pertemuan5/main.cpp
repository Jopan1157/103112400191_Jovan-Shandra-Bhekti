#include "listBuah.h"

#include <iostream>
using namespace std;
int main() {
    linkedlist list ;
    address nodeA,nodeB,nodeC,nodeD,nodeE=Nil;
    createList(list);
    
    dataBuah dibuah;

    nodeA = alokasi ("jeruk",100,3000);
    nodeB = alokasi ("apel",75,4000);
    nodeC = alokasi ("pir",87,5000);
    nodeD = alokasi ("semangka",43,11500);
    nodeE = alokasi ("durian",15,31450);

    insertFirst(list,nodeA);
    insertLast(list,nodeB);
    insertafter(list,nodeC,nodeA);
    insertafter(list,nodeD,nodeC);
    insertLast(list,nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(list);
    cout << "Jumlah Node : " << nblist(list) << endl;
    cout << endl;

    updatefirst(list);
    updatelast(list);
    updateafter(list,nodeD);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(list);
    cout << "Jumlah Node : " << nblist(list) << endl;
    cout << endl;

    return 0;
}