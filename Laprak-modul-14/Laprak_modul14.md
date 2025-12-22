# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Jovan Shandra Bhekti - 103112400191</p>

## Dasar Teori
Graph merupakan salah satu struktur data non-linear yang digunakan untuk merepresentasikan hubungan atau keterkaitan antar objek. Secara umum, graph terdiri dari dua komponen utama, yaitu vertex (simpul) yang merepresentasikan objek dan edge (sisi) yang menunjukkan hubungan antar simpul. Struktur data graph banyak digunakan dalam berbagai bidang, seperti jaringan komputer, sistem transportasi, media sosial, dan pemodelan hubungan data [1].

Dalam penelusuran graph, terdapat dua algoritma dasar yang sering digunakan, yaitu Depth First Search (DFS) dan Breadth First Search (BFS). DFS melakukan penelusuran secara mendalam dari satu simpul ke simpul lainnya hingga tidak ditemukan simpul yang belum dikunjungi, kemudian kembali ke simpul sebelumnya. Sementara itu, BFS melakukan penelusuran secara melebar dengan mengunjungi semua simpul tetangga terlebih dahulu sebelum berpindah ke tingkat berikutnya, biasanya dengan bantuan struktur data queue [2].

### A. Graph <br/>
Graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antar objek. Graph terdiri dari kumpulan node (simpul/vertex) dan edge (sisi) yang menghubungkan satu node dengan node lainnya.

## Guided 

### 1. Soal guided 1
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
  adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
#endif
```
graph_edge.cpp
```C++
#include "graph.h"
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if(P->info == X){
            P = P -> next;
        }
        return NULL;
    }
}
void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if(pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;//insert first di list edge
        pStart->firstEdge = newEdge;
    }
    
}

```
graph_init.cpp
```C++
#include "graph.h"
void createGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;

    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node" << P->info << "Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```
main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');//nambah node A,B,C,D
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //hub8ngkan node gd edge
    connectNode(G,'A','B'); // A ke B
    connectNode(G,'A','C'); // A ke C
    connectNode(G, 'B','D'); // B ke D
    connectNode(G, 'C','D'); // C ke D

    cout << "Isi graph :" << endl;
    printGraph(G);

}
```
Program ini menerapkan struktur data graph berarah menggunakan daftar terhubung, di mana informasi untuk setiap node terdiri dari karakter dan daftar tepi yang menunjukkan hubungan antar node. Graph dimulai dalam keadaan kosong. Kemudian ditambahkan node A, B, C, dan D. Selanjutnya, tepi satu arah digunakan untuk membuat hubungan antara A dan B, A dan C, B dan D. Setiap node menyimpan daftar node tujuan yang terhubung dengannya dalam bentuk daftar adjacency. Terakhir, isi graph ditampilkan dengan mencetak setiap node dan hubungannya. Ini membuat struktur hubungan antar node jelas.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Graph tidak berarah file “graph.h”.Buatlah implementasi ADT Graph pada file“graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp”.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
#endif           
```
graph.cpp
```C++
#include "graph.h"
void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);
    PrintInfoGraph(G);
    return 0;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-14/ss-jwb-no1.png)

Program ini adalah penerapan struktur data graph tak berarah menggunakan linked list dalam bahasa C++. Graph dibentuk dari node-node yang menyimpan sebuah karakter dan daftar edge sebagai adjacency list. Awalnya graph dibuat kosong, lalu ditambahkan node A hingga H. Setiap node dihubungkan melalui fungsi ConnectNode yang membuat hubungan dua arah. Setelah semua hubungan terbentuk, fungsi PrintInfoGraph digunakan untuk menampilkan setiap node beserta node-node yang terhubung. Program ini memperlihatkan cara membuat, menghubungkan, dan menampilkan graph tak berarah dengan linked list.

### 2. Soal unguided 2
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
void printDFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           
```
graph.cpp
```C++
#include "graph.h"
void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}

void printDFS(Graph G, adrNode N){
    if(N != NULL && N->visited == 0){
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while(E != NULL){
            if(E->node->visited == 0){
                printDFS(G, E->node);
            }
            E = E->next;
        }
    }
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);

    Visited(G);
    cout << "Hasil penulusuran DFS : " ;
    printDFS(G, a);
    cout << endl ;
    //PrintInfoGraph(G);
    return 0;

}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-14/ss-jwb-no2.png)

Program ini merupakan implementasi graph tak berarah menggunakan linked list dengan metode penelusuran Depth First Search (DFS). Graph dibuat dengan menambahkan node A sampai H dan dihubungkan dua arah, sehingga setiap node dapat ditelusuri bolak-balik. Setiap node memiliki penanda visited untuk mencegah kunjungan berulang. Sebelum DFS dijalankan, semua node diatur menjadi belum dikunjungi, lalu proses DFS dimulai dari node A dan menampilkan urutan node yang dikunjungi.

### 3. Soal unguided 3
Buatlah prosedur untuk menampilkan hasil penelusuran BFS.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
void printBFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           
```
graph.cpp
```C++
#include "graph.h"
#include<queue>

void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}
void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);

    Visited(G);
    cout << "Hasil penulusuran BFS : " ;
    printBFS(G, a);
    cout << endl ;
    
    return 0;

}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Jopan1157/103112400191_Jovan-Shandra-Bhekti/blob/main/Laprak-modul-14/ss-jwb-no3.png)

Program ini adalah implementasi graph tak berarah menggunakan linked list dengan algoritma Breadth First Search (BFS). Graph dibuat dengan node A sampai H yang saling terhubung dua arah, sehingga setiap node memiliki daftar tetangga. Setiap node memiliki penanda visited untuk mengetahui apakah sudah dikunjungi. Sebelum BFS dijalankan, semua node diatur menjadi belum dikunjungi. Proses BFS dimulai dari node A menggunakan queue, lalu menampilkan urutan node yang dikunjungi.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data graph dapat diimplementasikan menggunakan linked list dengan representasi adjacency list untuk menyimpan hubungan antar node secara efisien. Implementasi graph berarah dan tak berarah berhasil dilakukan dengan menambahkan node serta menghubungkannya menggunakan edge sesuai kebutuhan.

Selain itu, algoritma Depth First Search (DFS) dan Breadth First Search (BFS) dapat digunakan untuk menelusuri graph dengan cara yang berbeda. DFS melakukan penelusuran secara mendalam hingga mencapai node terdalam terlebih dahulu, sedangkan BFS menelusuri graph secara melebar dengan mengunjungi node-node terdekat terlebih dahulu menggunakan struktur data queue. Penggunaan penanda visited terbukti penting untuk mencegah kunjungan berulang pada node yang sama selama proses penelusuran.

## Referensi
[1] S. Wahyuni dan R. Kurniawan, “Implementasi Struktur Data Graph pada Sistem Informasi,” Jurnal Teknologi Informasi dan Komputer, vol. 5, no. 2, pp. 45–52, 2019.
[2] M. Hidayat, “Implementasi Algoritma DFS dan BFS pada Struktur Data Graph,” Jurnal Teknik Informatika, vol. 9, no. 1, pp. 25–32, 2022.
