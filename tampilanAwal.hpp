#include <iostream>
#pragma once

const std::string username = "AdminZihava";
const std::string password = "siyangpunyazihava";

void tampilanAwal(int &pilihan)
{
    system("cls");
    std::cout   << "====================================\n"
                << "|            TOKO ZIHAVA           |\n"
                << "====================================\n"
                << "| 1. User                          |\n"
                << "| 2. Admin                         |\n"
                << "====================================\n"
                << "Masukkan Pilihan : ";
    do
    {
        std::cin >> pilihan;
    } while (pilihan < 1 || pilihan > 2 || (pilihan - int(pilihan)) != 0);
    
}

void tampilanUser(int &pilihan)
{   
    system("cls");
    std::cout   << "====================================\n"
                << "|            TOKO ZIHAVA           |\n"
                << "====================================\n"
                << "| 1. Jual barang                   |\n"
                << "| 2. Beli barang                   |\n"
                << "| 3. Tampilkan keranjang           |\n"
                << "| 0. Exit                          |\n"
                << "====================================\n"
                << "Masukkan Pilihan : ";
    do
    {
        std::cin >> pilihan;
    } while (pilihan < 0 || pilihan > 3 || (pilihan - int(pilihan)) != 0);
}

bool loginAdmin()
{
    std::string un;
    std::string pw;
    bool login;
    do{
        system("cls");
        std::cout   << "============================================================\n"
                    << "                         Login Admin                        \n"
                    << "============================================================\n";
        std::cout   << "Username   = "; std::cin>>un;
        std::cout   << "Password   = "; std::cin>>pw;
        std::cout   << "============================================================\n";

        if(un == username && pw == password){
            std::cout<<"Sukses Login Akun Admin!!\n";
            login = true;
        }
        else{
            std::cout<<"Masukkan Username dan password yang benar!!\n";
            login = false;
            system("pause");
        }
    }while(login == false);
    return login;
}