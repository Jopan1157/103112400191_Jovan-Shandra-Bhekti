#ifndef mutlilist_h
#define mutlilist_h

#include <iostream>

using namespace std;
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild
{
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak 
{
    NodeChild first;
    NodeChild last;
};

struct nodeParent
{
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk 
{
    NodeParent first;
    NodeParent last;
};  

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

//alokasi & dealokasi anak
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent (listInduk &Linduk,NodeParent nodePrev);

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild (listAnak &LAnak,NodeChild nodePrev);
void findChildByID (listInduk &LInduk,string IDcari);

void printStrukturMLL(listInduk &LInduk);
#endif

