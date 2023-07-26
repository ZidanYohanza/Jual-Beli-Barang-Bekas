#pragma once
#include<iostream>
#include<iomanip>

void tampilanPemilihan(int &pilihan)
{
    std::cout   << "====================================\n"
                << "|          Dashboard Admin         |\n"
                << "====================================\n"
                << "| 1. Transaksi Barang              |\n"
                << "| 2. Update Barang Jual            |\n"
                << "| 3. Lihat Data Barang             |\n"
                << "| 0. Logout                        |\n"
                << "====================================\n"
                << "Masukkan Pilihan : ";
    do
    {
        std::cin >> pilihan;
    } while (pilihan < 0 || pilihan > 3 || (pilihan - int(pilihan)) != 0);
}

void traversalBarang(Queue &q){
    int i=1;
    if (q.head == nullptr){ 
        std::cout << "List kosong!\n";
    } else { 
        system ("cls");
        LinkedList barangPrint = q.head;
        std::cout << "============================================================================================\n";
        std::cout << "No"<< std::setw(10) << "Nama Barang" << std::setw(20) << "Harga" << std::setw(20);
        std::cout << "Kondisi" << std::setw(20) << "Deskripsi" << std::endl;
        std::cout << "============================================================================================\n";
        do{
            std::cout << i << std::setw(10) << barangPrint->data.nama << std::setw(20);
            std::cout << barangPrint->data.harga << std::setw(20) << barangPrint->data.kondisi << std::setw(20); 
            std::cout << barangPrint->data.deskripsi << std::setw(20) << std::endl;
            i++;
            barangPrint = barangPrint->next;
        }while(barangPrint != nullptr);
        std::cout << "============================================================================================\n";
    }
}