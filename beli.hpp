#pragma once
#include <iostream>
#include <iomanip>

bool isQueueEmpty(Queue Q){
    return (Q.head == NULL);
}
void traversal(Queue Q){
    pointer pTemp = Q.head;
    int index = 1;
    if(Q.head == nullptr && Q.tail == nullptr){
        std::cout << "Kosong\n";
    } else {
        std::cout << std::setw(7) << "No. "<< std::setw(35) << "Nama Barang" << std::setw(30) <<  "Kondisi" << std::setw(20) << "Harga" <<  '\n';
        do{
            std::cout << std::setw(7) << index++ << std::setw(35) << pTemp->data.nama << std::setw(30) <<  pTemp->data.kondisi << std::setw(20) << pTemp->data.harga <<  '\n';
            pTemp = pTemp->next;
        }while(pTemp != NULL);
    }
}
void ListBarang(Queue barang){
    std::cout << "==================================================================\n"
              << "                             BELI BARANG\n"
              << "==================================================================\n";
    traversal(barang);
    std::cout << "==================================================================\n";
}

void linearSearch(Queue barang, std::string namaBarang, pointer &barangCari, bool &found){
    pointer pTemp = barang.head;
    found = false;
    while(pTemp != NULL && !found){
        if(pTemp->data.nama == namaBarang){
            barangCari = pTemp;
            found = true;
            return;
        }
        pTemp = pTemp->next;
    }
}
void deleteByNama(Queue &barang, pointer barangCari, pointer &barangHapus){
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
void detailBarang(pointer barang){
    std::cout << "==================================================================\n"
              << "Data Barang  \n"
              << "Nama      : " << barang->data.nama << '\n'
              << "Harga     : " << barang->data.harga << '\n'
              << "Kondisi   : " << barang->data.kondisi << '\n'
              << "Deskripsi : " << barang->data.deskripsi << "\n\n";

    std::cout << "Data Penjual  \n"
              << "Nama      : " << barang->data.user.nama << '\n'
              << "Telepon   : " << barang->data.user.telp << '\n'
              << "Kondisi   : " << barang->data.user.alamat << '\n';
    std::cout << "==================================================================\n";
}
void push(Stack &TOP, pointer barang){
    if(TOP == NULL){
        TOP = barang;
    } else {
        barang->next = TOP;
        TOP = barang;
    }
}
void BeliBarang(Queue &barangJual, Stack &keranjang){
    std::string namaBarang;
    pointer barangCari, barangHapus;
    char opsi;
    bool found = false, membeli = true;

    if(isQueueEmpty(barangJual)){
        std::cout << "Tidak ada barang yang dijual\n\n";
        system("pause");
        return;
    } else {
        while(membeli){
            system("cls");
            //Tampilkan list barang
            ListBarang(barangJual);
        
            //Pilih barang yang akan dibeli
            std::cout << "Masukan nama barang yang ingin dibeli: ";
            std::cin.ignore();
            getline(std::cin, namaBarang);

            //search ke list barang
            linearSearch(barangJual, namaBarang, barangCari, found);

            if(found){ //Jika ditemukan
                //Tampilkan detail
                detailBarang(barangCari);
                std::cout << "Masukan barang ke keranjang [Y/N] :";
                std::cin >> opsi;
                if(opsi == 'Y' || opsi == 'y'){
                    //hapus dari list barang
                    //tambahkan ke keranjang
                    deleteByNama(barangJual, barangCari, barangHapus);
                    push(keranjang, barangHapus);
                    std::cout << "Barang berhasil ditambahkan\n";
                    system("pause");
                    return;
                }else {
                    break;
                }
            } else {
                std::cout << "Barang tidak ditemukan\n";
            }
        }
    }
}