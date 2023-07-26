#pragma once
#include <iostream>
#include <iomanip>

void createStack(Stack &TOP){
    TOP = NULL;
}
void traversalStack(Stack TOP){
    pointer pTemp = TOP;
    int index = 1;
    if(TOP == NULL){
        std::cout << "Kosong\n";
    } else {
        std::cout << std::setw(7) << "No. "<< std::setw(35) << "Nama Barang" << std::setw(30) <<  "Kondisi" << std::setw(20) << "Harga" <<  '\n';
        do{
            std::cout << std::setw(7) << index++ << std::setw(35) << pTemp->data.nama << std::setw(30) <<  pTemp->data.kondisi << std::setw(20) << pTemp->data.harga <<  '\n';
            pTemp = pTemp->next;
        }while(pTemp != NULL);
    }
}
void listKeranjang(Stack TOP){
    system("cls");
    std::cout << "==================================================================\n"
              << "                             KERANJANG\n"
              << "==================================================================\n";
    traversalStack(TOP);
    std::cout << "==================================================================\n";
}

void pilihanKeranjang(int &pilihan){
    std::cout << "1. Tambah Barang\n"
              << "2. Hapus Barang\n"
              << "3. Bayar\n";
    std::cout << "==================================================================\n";
    std::cout << "Masukkan pilihan: ";
    std::cin >> pilihan;  std::cin.ignore();
}
void deleteByNama(Stack &TOP, pointer barangCari, pointer &barangHapus){
    if(barangCari == TOP){ //item 1
        barangHapus = TOP;
        TOP = NULL;
        barangHapus->next = NULL;
        std::cout << "Barang terhapus dari Stack";
    } else if(barangCari == TOP->next){ //item di akhir
        pointer pPrev = TOP;
        while(pPrev->next != TOP->next){
            pPrev = pPrev->next;
        }
        barangHapus = TOP->next;
        TOP = pPrev;
        pPrev->next = NULL;
        barangHapus->next = NULL;
        std::cout << "Barang terhapus dari Stack";
    } else{
        pointer pPrev = TOP;
        while(pPrev->next != barangCari){
            pPrev = pPrev->next;
        }
        barangHapus = barangCari;
        pPrev->next = barangCari->next;
        barangHapus->next = NULL;
        std::cout << "Barang terhapus dari Stack";
    }
}
void linearSearch(Stack TOP, std::string key, pointer &barangCari, int &found){
    pointer pTemp = TOP;
    std::cout << "Masukkan nama barang yang ingin dicari: ";
    getline(std::cin, key);
    while(pTemp != NULL && !found){
        if(pTemp->data.nama == key){
            barangCari = pTemp;
            found = true;
            break;
        }
        pTemp = pTemp->next;
    }
    if(found){
        std::cout << "Barang ditemukan\n";
    } else {
        std::cout << "Barang tidak ditemukan\n";
    }
}