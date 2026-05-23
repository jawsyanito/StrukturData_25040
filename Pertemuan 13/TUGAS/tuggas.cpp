#include <iostream>
using namespace std;

int main() {
    // Data array
    int arr[] = {9, 2, 5, 2, 7, 6, 11, 2};

    // Jumlah elemen array
    int n = 8;

    //Untuk mencari angka pada arraynya
    int cari;
    cout << "Masukan angka yang akan dicari : ";
    cin >> cari;

    // Variabel untuk menghitung total kemunculan
    int jumlah = 0;

    cout << "Angka " << cari << " ditemukan pada indeks: ";

    // Sequential Search sekaligus mencetak angka yang cocok
    for (int i = 0; i < n; i++) {
        if (arr[i] == cari) {
            cout << i << " ";
            jumlah++;
        }
    }

    //Nampilin indeks = none jika tidak ditemukan angka yang sama 
    if (jumlah == 0){
        cout << "None";
    }

    // Menampilkan total kemunculan
    cout << "\nTotal kemunculan angka " << cari << " = " << jumlah << " kali" << endl;

    return 0;
}