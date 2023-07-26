#include <iostream>
#include "struct.hpp"
#include "tampilanAwal.hpp"
#include "bayar.hpp"
#include "beli.hpp"
#include "jual.hpp"
#include "admin.hpp"
#include "keranjang.hpp"

int main()
{
    Stack keranjang;
    Queue barangJual;
    User pembeli, penjual;
    pointer barang, barangHapus, barangCari;
    int pilihan, hargaTotal = 0, found, opsiKeranjang;
    char keluar;
    bool stop = false, stopKeranjang = false;
    char key[30];

    createQueue(barangJual);
    createStack(keranjang);
    //Tampilan Awal
    while(!stop){
        tampilanAwal(pilihan);
        
        //user
        if(pilihan == 1){
            bool stopUser = false;
            int pilihanUser;

            while(!stopUser){
                tampilanUser(pilihanUser); //tampilan user
                switch(pilihanUser){
                    
                    case 1: // JUAL BARANG
                        int opsiJual;
                        jualBarang(barangJual, penjual, barang);

                        tampilanPilihan(opsiJual);
                        switch(opsiJual){
                            case 1:
                                mainAdd(barangJual, barang, penjual);
                                break;
                            case 2:
                                deleteBarang(barangJual, barangCari, barangHapus);
                                break;
                            case 3:
                                search(barangJual, key, found, barangCari);
                                if(found){
                                    editBarang(barangCari);
                                }
                                break;
                            case 0:
                                stopUser = true;
                                break;
                        }
                        break;


                    case 2:
                        // Beli Barang
                        beli:
                        BeliBarang(barangJual, keranjang);
                        break;


                    case 3:

                        while(!stopKeranjang){
                            // Lihat keranjang
                            listKeranjang(keranjang);
                            
                            pilihanKeranjang(opsiKeranjang);
                            switch(opsiKeranjang){
                                case 1:
                                    //Tambah
                                    goto beli;
                                    break;
                                case 2:
                                    //Hapus dari nama
                                    linearSearch(keranjang, key, barangCari, found);
                                    if(found){
                                        deleteByNama(keranjang, barangCari, barangHapus);
                                    }else{
                                        std::cout << "Barang tidak ditemukan\n";
                                        system("pause");
                                    }
                                    break;
                                case 3:
                                    //Bayar
                                    mainBayar(keranjang, pembeli, hargaTotal);
                                    std::cout   <<"TERIMAKASIH SUDAH BERBELANJA!!!\n"
                                                <<"Silahkan Datang Kembali!\n"
                                                <<"Keluar Program (Y/N) = ";
                                    std::cin    >> keluar;
                                    if(keluar == 'Y' || keluar == 'y'){
                                        stopUser = true;
                                        stop = true;
                                        stopKeranjang = true;
                                    }
                                    break;
                            }              
                        }
                    case 0:
                        // keluar program
                        stopUser = true;
                        break;
                    default:
                        std::cout << "Pilihan tidak ada\n";
                        break;
                }
            }
        } else if(pilihan == 2){ // Admin
            //loginAdmin
            if(loginAdmin()){
                bool stopAdmin = false;
                int pilihanAdmin;

                while(!stopAdmin){
                    tampilanPemilihan(pilihanAdmin);

                    switch(pilihanAdmin){
                        case 1:
                            //liat transaksi
                            mainBayar(keranjang, pembeli, hargaTotal);
                        case 2:
                            int opsiUpdate;
                            //update barang
                            tampilanPilihan(opsiUpdate);
                            switch(opsiUpdate){
                                case 1:
                                    mainAdd(barangJual, barang, penjual);
                                    break;
                                case 2:
                                    deleteBarang(barangJual, barangCari, barangHapus);
                                    break;
                                case 3:
                                    search(barangJual, key, found, barangCari);
                                    if(found){
                                        editBarang(barangCari);
                                    }
                                    break;
                                case 0:
                                    stopAdmin = true;
                                    break;
                            }
                            break;
                        case 3:
                            traversalBarang(barangJual);
                            break;
                    }
                }
            }else{
                std::cout << "Login admin gagal!\n";
            }
        }
    }
}