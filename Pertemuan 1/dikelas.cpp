#include <iostream>
using namespace std;

int main() {

    // CARA 1: DEKLARASI DULU (PESAN TEMPAT)
    cout << "CONTOH 1: ARRAY ANGKA (CARA MANUAL)" << endl;

    int nilai[5]; // Pesan 5 loker (indeks 0-4)

    // Isi loker satu per satu
    nilai[0] = 80;
    nilai[1] = 90;
    nilai[2] = 75;
    nilai[3] = 60;
    nilai[4] = 100;

    // Nampilin satu data aja (manual)
    cout << "Nilai indeks ke-1 adalah: " << nilai[1] << endl;
    cout << "Nilai indeks ke-4 adalah: " << nilai[4] << endl;

    // Ganti isi data (update)
    nilai[0] = 85; // Loker 0 diganti jadi 85
    cout << "Nilai indeks ke-0 setelah diganti: " << nilai[0] << endl;

    cout << endl; // Enter biar rapi

    // CARA 2: INISIALISASI LANGSUNG (PRAKTIS)
    cout << "--- CONTOH 2: ARRAY STRING (LANGSUNG ISI) ---" << endl;

    // Ukuran otomatis mengikuti jumlah isinya (di sini ada 4)
    string namaAslab[] = {"Rizkian", "Budi", "Siti", "Joko"};

    // Nampilin semua data pakai looping (for)
    // Ingat: mulai dari 0, berhenti sebelum 4 (i < 4)
    for (int i = 0; i < 4; i++) {
        cout << "Loker ke-" << i << " isinya: " << namaAslab[i] << endl;
    }

    return 0;
}