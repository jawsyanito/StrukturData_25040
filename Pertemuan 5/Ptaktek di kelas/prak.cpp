#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Struktur Data KTP
struct dataKtp {
    char nama[50];
    char alamat[50];
    char golongandarah[2];
    dataKtp *next, *prev; // Dua tautan: depan dan belakang
};

dataKtp *awal = NULL, *akhir = NULL, *bantu, *baru;

// Fungsi Input di Depan
void inputDatadepan() {
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;

    cout << "Nama\t\t: "; cin >> baru->nama;
    cout << "Alamat\t\t: "; cin >> baru->alamat;
    cout << "Golongan darah : "; cin >> baru->golongandarah;

    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }

    system("cls");
}

// Fungsi Input di Belakang
void inputDatabelakang() {
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;

    cout << "Nama\t\t: "; cin >> baru->nama;
    cout << "Alamat\t\t: "; cin >> baru->alamat;
    cout << "Golongan darah : "; cin >> baru->golongandarah;

    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }

    system("cls");
}

// Fungsi Menampilkan Data
void outputData() {
    bantu = awal;

    while (bantu != NULL) {
        cout << "Nama\t\t: " << bantu->nama << endl;
        cout << "Alamat\t\t: " << bantu->alamat << endl;
        cout << "Golongan darah : " << bantu->golongandarah << endl;
        cout << "---------------------" << endl;

        bantu = bantu->next;
    }
}

int main() {
    int pilihan;

    do {
        cout << "-DOUBLE LINKED LIST-\n";
        cout << "Pilih menu: \n";
        cout << "1. Input data di depan\n";
        cout << "2. Input data di belakang\n";
        cout << "3. Output data\n";
        cout << "4. EXIT\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            inputDatadepan();
            break;

        case 2:
            inputDatabelakang();
            break;

        case 3:
            if (awal == NULL) {
                cout << "Data masih kosong !\n";
            } else {
                outputData();
            }
            break;

        case 4:
            cout << "EXIT";
            break;

        default:
            break;
        }

        getch();

    } while (pilihan <= 3);

    return 0;
}
