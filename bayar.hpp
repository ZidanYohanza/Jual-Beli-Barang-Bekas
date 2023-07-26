#pragma once
#include<iostream>
#include<iomanip>

void dataPembeli(User &pembeli);

void display(Stack keranjang, int &hargaTotal);

void pembayaran(int hargaTotal);

void mainBayar(Stack &keranjang, User &pembeli, int &hargaTotal)
{
    dataPembeli(pembeli);
    display(keranjang, hargaTotal);
    pembayaran(hargaTotal);
}
void dataPembeli(User &pembeli)
{
    std::cout   << "============================================================\n"
                << "                        Bayar Barang                    \n"
                << "============================================================\n"
                << "Masukkan Data Pembeli :                                 \n";
    std::cout   << "Nama   = "; std::cin.ignore(); std::cin.getline(pembeli.nama, 30); 
    std::cout   << "Telp   = "; std::cin.getline(pembeli.telp,30); 
    std::cout   << "Alamat = "; std::cin.getline(pembeli.alamat,30); 
    std::cout   << "============================================================\n";
}

void display(pointer keranjang, int &hargaTotal){
    int n = 1, harga = 0;
    pointer temp = keranjang;

    if(keranjang == nullptr){
        std::cout << "Linked List kosong\n";
    } 
    
    else{
        system("cls");
        std::cout   << "============================================================\n"
                    << "Data Barang yang mau dibayar :                          \n"
                    << "No." << std::setw(7) << "Nama Barang" << std::setw(20) << "Kondisi" << std::setw(20) << "Harga\n";

        do{
            std::cout << n++ << std::setw(7) << temp->data.nama << std::setw(20) << temp->data.kondisi << std::setw(20) << temp->data.harga <<  std::endl;
            harga += temp->data.harga; 
            temp = temp->next;
        }while(temp->next != nullptr);

        std::cout   << std::setw(47) << "=========== +\n" 
                    << std::setw(47) << harga
                    << "=============================================================\n\n";
    }
}

void pembayaran(int hargaTotal){
    int harga, kembalian;
    std::cout   << "Total Harga                : Rp" << hargaTotal << std::endl;
    std::cout   << "Masukkan Nominal           : Rp"; std::cin >> harga;

    ulang:
    if (harga > hargaTotal)
    {
        harga -= hargaTotal; 
        std::cout   << "Uang anda tersisa = Rp"
                    << harga << std::endl;
    }

    else if (harga < hargaTotal)
    {
        hargaTotal -= harga; 
        std::cout  << "Uang anda kurang sebanyak Rp" << hargaTotal << ", Silahkan masukkan nomimal kembali!\n"
                   << "Masukkan Nominal           : Rp";  std::cin >> harga;       
        goto ulang;
    }

}