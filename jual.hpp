#pragma once
#include<iostream>
#include<iomanip>

void createQueue(Queue& queue);

void dataPenjual(User &penjual);

void dataBarang(pointer &barangJual, User user);

void insertBarang(Queue& queue, pointer barangJual);

void tampilanPilihan(int& pilihan);
// void createUser(User &user){
//     user.nama = "Varian";
//     user.telp = "123";
//     user.alamat = "asd";
// }
// void createBarang(pointer &B, User user){
//     B = new Node;
//     B->data.nama = "Buku";
//     B->data.harga = 100000;
//     B->data.deskripsi = "Buku";
//     B->data.kondisi = "Baru";
//     B->data.user = user;
//     B->next = NULL;
//     B->prev = NULL;
//     std::cout << "data barang berhasil dibuat" << std::endl;
// }
void jualBarang(Queue& queue, User &penjual, pointer &barangJual)
{   
    dataPenjual(penjual);
    dataBarang(barangJual, penjual);
    insertBarang(queue, barangJual);
}

void mainAdd(Queue& queue, pointer &barangJual, User penjual){
    dataBarang(barangJual, penjual);
    insertBarang(queue, barangJual);
}
void createQueue(Queue& queue) {
    queue.head = nullptr;
    queue.tail = nullptr;
}

void dataPenjual(User &penjual)
{
    system("cls");
    std::cout   << "============================================================\n"
                << "                        Jual Barang                    \n"
                << "============================================================\n"
                << "Masukkan Data Penjual :                                 \n";
    std::cout   << "Nama   = "; std::cin.ignore(); std::cin.getline(penjual.nama, 30); 
    std::cout   << "Telp   = "; std::cin.getline(penjual.telp, 30); 
    std::cout   << "Alamat = "; std::cin.getline(penjual.alamat, 30); 
}

void dataBarang(pointer &barangJual, User penjual){
    barangJual = new Node;
    std::cout   << "\nMasukkan Data Barang :                                 \n";
    std::cout   << "Nama      = "; std::cin.getline(barangJual->data.nama, 30); 
    std::cout   << "Harga     = "; std::cin >> barangJual->data.harga;  
    std::cout   << "Kondisi   = "; std::cin.ignore(); std::cin.getline(barangJual->data.kondisi, 30); 
    std::cout   << "Deskripsi = "; std::cin.getline(barangJual->data.deskripsi, 30); 
    std::cout   << "============================================================\n";
    barangJual->data.user = penjual;
    barangJual->next = nullptr;
}

void insertBarang(Queue& queue, pointer barangJual) {
    if (queue.head == nullptr && queue.tail == nullptr) {
        queue.head = barangJual;
        queue.tail = barangJual;
    }
    else{
        queue.tail->next = barangJual;
        queue.tail = barangJual;
    }
    std::cout << "Data Sudah ditambahkan!!\n";
    system("pause");
}

void insertBarang(Queue& q, pointer barangJual) {
    if (q.head == nullptr && q.tail == nullptr) {
        q.head = q.head->next;
        std::cout<<"Data sudah dihapus!!";
    }
}

void tampilanPilihan(int& pilihan){
    system("cls");
    std::cout   << "============================================================\n"
                << " 1. Tambah barang                                           \n"
                << " 2. Hapus barang                                            \n"
                << " 3. Edit Barang                                             \n"
                << " 0. Kembali                                                 \n"
                << "============================================================\n"
                << "Masukkan Pilihan : ";
    do
    {
        std::cin >> pilihan; std::cin.ignore(); 
    } while (pilihan < 0 || pilihan > 3 || (pilihan - int(pilihan)) != 0);
}

void search(Queue& q, std::string key, int& found, pointer& pCari){
    found=0; 
    pCari=q.head;
    std::cout << "Masukkan Nama Barang yang dicari : ";

    getline(std::cin, key);
    while (found==0 && pCari!=nullptr) { 
        if (pCari->data.nama == key){
            found = 1;
            break;
        }else{ 
            pCari=pCari->next;
        }
    } 

    if (found == 1) {
        std::cout<<"Data Ditemukan!!\n";
    } else {
        std::cout<<"Data Tidak Ditemukan " << std::endl;
    }
}

void deleteBarang(Queue &barang, pointer barangCari, pointer &barangHapus){
    if(barangCari == barang.head){ //item 1
        barangHapus = barang.head;
        barang.head = NULL;
        barang.tail = NULL;
        barangHapus->next = NULL;
    } else if(barangCari == barang.tail){ //item di akhir
        pointer pPrev = barang.head;
        while(pPrev->next != barang.tail){
            pPrev = pPrev->next;
        }
        barangHapus = barang.tail;
        barang.tail = pPrev;
        pPrev->next = NULL;
        barangHapus->next = NULL;
    } else{
        pointer pPrev = barang.head;
        while(pPrev->next != barangCari){
            pPrev = pPrev->next;
        }
        barangHapus = barangCari;
        pPrev->next = barangCari->next;
        barangHapus->next = NULL;
    }
}

void editBarang(pointer& pCari){
    std::cout << "Edit Nama      = "; std::cin.getline(pCari->data.nama, 30);
    std::cout << "Edit Harga     = "; std::cin >> pCari->data.harga;
    std::cout << "Edit Kondisi   = "; std::cin.ignore(); std::cin.getline(pCari->data.kondisi, 30); 
    std::cout << "Edit Deskripsi = "; std::cin.getline(pCari->data.deskripsi, 30); 
    std::cout << "\nData Sudah Diedit!!\n";
}
