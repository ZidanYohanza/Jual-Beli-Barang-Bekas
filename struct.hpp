#pragma once

struct User
{
    char nama[30];
    char telp[30];
    char alamat[30];
};

struct Barang
{
    char nama[30];
    int harga;
    char deskripsi[30];
    char kondisi[30];
    User user;
};

struct Node
{
    Barang data;
    Node *next;
};

typedef Node* pointer;
typedef pointer LinkedList;
typedef pointer Stack;

struct Queue{
    pointer head;
    pointer tail;
};
Queue Q;
