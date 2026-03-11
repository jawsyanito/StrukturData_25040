#include <iostream>
using namespace std;


struct mataKuliah{
    string TI;
    string SYSFOR;
};

struct mahasiswa {
    string nama;
    string npm;
    float ipk;
    mataKuliah matkul;
};

int main(){
    string uji;
    mahasiswa mhs[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukan nama mahasiswa ke - " << ( i + 1 ) << " : ";
        cin >> mhs[i].nama;
        cout << "Masukan npm mahasiswa ke - " << ( i + 1 ) << " : ";
        cin >> mhs[i].npm;
        cout << "Masukan ipk mahasiswa ke - " << ( i + 1 ) << " : ";
        cin >> mhs[i].ipk; 
        cout << "Masukan prodi mahasiswa ke - " << ( i + 1 ) << " : (sisfor/informatika) ";
        cin >> uji;
        if (uji == "sisfor" ){
            cin 
        }
    }

    cout << "\n=========================================\n";

    for (int i = 0; i < 5; i++) {    
        cout << "Mahasiswa ke - " << i + 1 << endl;
        cout << "nama : " << mhs[i].nama << endl;
        cout << "mpm : " << mhs[i].npm << endl;
        cout << "ipk : " << mhs[i].ipk << endl;
    }

    return 0;
}