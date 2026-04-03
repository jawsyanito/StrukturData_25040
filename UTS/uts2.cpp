#include <iostream>
using namespace std;

// Struct Mahasiswa
struct Mahasiswa {
    string npm;
    string nama;
    int nilai;
};

int main() {
    int jumlahMhsw;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlahMhsw;

    //Klarifikasi jumlah mahasiswa kurang dari 10
    if (jumlahMhsw > 10) {
        cout << "Maksimal input hanya 10" << endl;
        return 0;
    }

    Mahasiswa dataMhsw[jumlahMhsw];     // array of struct
    Mahasiswa *ptr = dataMhsw;  // pointer ke array

    // Input data mahasiswa
    cout << "\nInput Data Mahasiswa" << endl;
    for (int i = 0; i < jumlahMhsw; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "NPM   : ";
        cin >> (ptr + i) -> npm;

        cout << "Nama  : ";
        cin >> (ptr + i) -> nama;

        cout << "Nilai : ";
        cin >> (ptr + i) -> nilai;
    }

    // Hitung rata-rata (pakai pointer)
    int total = 0;
    for (int i = 0; i < jumlahMhsw; i++) {
        total += (ptr + i) -> nilai;
    }

    float rata =  total / jumlahMhsw;

    // Output data mahasiswa (pakai pointer)
    cout << "\nData Mahasiswa " << endl;
    for (int i = 0; i < jumlahMhsw; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NPM   : " << (ptr + i)->npm << endl;
        cout << "Nama  : " << (ptr + i)->nama << endl;
        cout << "Nilai : " << (ptr + i)->nilai << endl;
    }

    cout << "\nRata-rata Nilai Kelas = " << rata << endl;

    return 0;
}