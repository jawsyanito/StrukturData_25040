#include <iostream>
using namespace std;

//Menyimpan Nilai absen dsb di struct Nilai
struct Nilai {
    float nilaiAbsen, nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
    char nilaiHuruf;
};

//Menyimpan data mahasiswa dalam struct Mahasiswa
struct Mahasiswa {
    string nama;
    string NPM;
    Nilai nilai;
};

//Fungsi untuk menampilkan menu untuk switch case nanti
void tampilMenu(){
    cout << "\nSilahkan pilih : " 
         << "\n1. Input data mahasiswa"
         << "\n2. Tampil data mahasiswa"
         << "\n3. Edit data mahasiswa"
         << "\n4. Hapus data mahasiswa" << endl;
}

//Hanya untuk salam diawal
void salam(){
    cout << "Selamat datang di program CRUD data mahasiswa";
}

//Menampilkan garis biar rapih
void garis(){
    cout << "\n====================================================\n";
}

int main () {

    Mahasiswa dataMahasiswa[20]; //Array mahasiswa max nya 20
    int jmlMhsw = 0;  //Inisiasi awal kalau mahasiswa kurang dari 20
    
    //Variabel untuk validasi dan sebagainya
    int pilih;
    int cariIndex;
    char isLanjut = 'y';
    char checkLanjut;
    string cariNPM;

    salam();
    
    while (isLanjut == 'y' ) {
        tampilMenu();
        cin >> pilih;

        
        switch (pilih) {
        case 1 :
            cout << "Anda memilih input data" << endl;
            garis();

            cout << "Masukan jumlah mahasiswa yang akan diinput (Maks 20) : ";
            cin >> jmlMhsw;

            //Jika jumlah mahasiswa yang diinput lebih dari 20 maka otomatis dibulatkan ke 20
            if (jmlMhsw > 20 ) {
                cout << "Maaf jumlah mahasiswa yang dapat diinput hanyalah 20 orang";
                jmlMhsw = 20;
            }

            garis();

            for (int i = 0; i < jmlMhsw; i++){

                //Proses input data mahasiswa sesuai index array
                cout << "\nData mahasiswa ke - " << (i+1) << endl;

                cout << "Nama : ";
                cin >> dataMahasiswa[i].nama;

                cout << "NPM : ";
                cin >> dataMahasiswa[i].NPM;

                cout << "Masukan Nilai " << endl;

                cout << "Absen : ";
                cin >> dataMahasiswa[i].nilai.nilaiAbsen;

                cout << "Tugas : ";
                cin >> dataMahasiswa[i].nilai.nilaiTugas;

                cout << "UTS : ";
                cin >> dataMahasiswa[i].nilai.nilaiUTS;

                cout << "UAS : ";
                cin >> dataMahasiswa[i].nilai.nilaiUAS;

                //Perhitungan untuk nilai akhir
                dataMahasiswa[i].nilai.nilaiAkhir =
                ((dataMahasiswa[i].nilai.nilaiAbsen * 0.1) +
                 (dataMahasiswa[i].nilai.nilaiTugas * 0.2) +
                 (dataMahasiswa[i].nilai.nilaiUTS * 0.3) +
                 (dataMahasiswa[i].nilai.nilaiUAS * 0.4));

                //Konversi nilai akhir ke nilai huruf
                if (dataMahasiswa[i].nilai.nilaiAkhir > 80 ) {
                    dataMahasiswa[i].nilai.nilaiHuruf = 'A';
                }
                else if (dataMahasiswa[i].nilai.nilaiAkhir > 70) {
                    dataMahasiswa[i].nilai.nilaiHuruf = 'B';
                }
                else if (dataMahasiswa[i].nilai.nilaiAkhir > 60) {
                    dataMahasiswa[i].nilai.nilaiHuruf = 'C';
                }
                else {
                    dataMahasiswa[i].nilai.nilaiHuruf = 'D';
                }
            }

            break;

        case 2 :
            cout << "\nAnda memilih tampilkan data";

            //Loop untuk tampilkan data
            for (int i = 0; i < jmlMhsw; i++){

                garis();

                cout << "Data mahasiswa ke - " << (i+1) << endl;

                cout << "Nama : " << dataMahasiswa[i].nama << endl;
                cout << "NPM : " << dataMahasiswa[i].NPM << endl;

                cout << "Nilai Akhir : " << dataMahasiswa[i].nilai.nilaiAkhir << endl;
                cout << "Nilai Huruf : " << dataMahasiswa[i].nilai.nilaiHuruf << endl;
            }

            break;

        case 3 :
            cout << "\nAnda memilih edit data" << endl;
            
            cout << "Masukan NPM yang ingin anda edit : ";
            cin >> cariNPM;

            //Mengubah data sesuai dengan NPM
            for (int i = 0; i < jmlMhsw; i++){

                //Input ulang data
                if (dataMahasiswa[i].NPM == cariNPM){

                    cout << "Silahkan masukan ulang data\n ";

                    cout << "Nama : ";
                    cin >> dataMahasiswa[i].nama;

                    cout << "NPM : ";
                    cin >> dataMahasiswa[i].NPM;

                    cout << "Masukan Nilai " << endl;

                    cout << "Absen : ";
                    cin >> dataMahasiswa[i].nilai.nilaiAbsen;

                    cout << "Tugas : ";
                    cin >> dataMahasiswa[i].nilai.nilaiTugas;

                    cout << "UTS : ";
                    cin >> dataMahasiswa[i].nilai.nilaiUTS;

                    cout << "UAS : ";
                    cin >> dataMahasiswa[i].nilai.nilaiUAS;

                    //Hitung ulang nilai akhir dan nilai huruf
                    dataMahasiswa[i].nilai.nilaiAkhir =
                    ((dataMahasiswa[i].nilai.nilaiAbsen * 0.1) +
                     (dataMahasiswa[i].nilai.nilaiTugas * 0.2) +
                     (dataMahasiswa[i].nilai.nilaiUTS * 0.3) +
                     (dataMahasiswa[i].nilai.nilaiUAS * 0.4));

                    if (dataMahasiswa[i].nilai.nilaiAkhir > 80 ) {
                        dataMahasiswa[i].nilai.nilaiHuruf = 'A';
                    }
                    else if (dataMahasiswa[i].nilai.nilaiAkhir > 70) {
                        dataMahasiswa[i].nilai.nilaiHuruf = 'B';
                    }
                    else if (dataMahasiswa[i].nilai.nilaiAkhir > 60) {
                        dataMahasiswa[i].nilai.nilaiHuruf = 'C';
                    }
                    else {
                        dataMahasiswa[i].nilai.nilaiHuruf = 'D';
                    }
                }
            }

            break;

        case 4 :
            cout << "\nAnda memilih hapus data " << endl;

            cout << "Masukan NPM data yang akan dihapus : ";
            cin >> cariNPM;

            //Loop untuk hapus data mahasiswa sesuai dengan NPM
            for (int i = 0; i < jmlMhsw; i++){

                if (dataMahasiswa[i].NPM == cariNPM){


                    cout << "Berikut data yang ingin dihapus : ";
                    cout << "Data mahasiswa ke - " << (i+1) << endl;

                    cout << "Nama : " << dataMahasiswa[i].nama << endl;
                    cout << "NPM : " << dataMahasiswa[i].NPM << endl;

                    cout << "Nilai Akhir : " << dataMahasiswa[i].nilai.nilaiAkhir << endl;
                    cout << "Nilai Huruf : " << dataMahasiswa[i].nilai.nilaiHuruf << endl;

                    cout << "Apakah anda ingin menghapus data tersebut ? (y/n) ";
                    cin >> checkLanjut;
                    
                    //Mengubah arraynya dengan menggeser data yang tak dihapus 
                    if (checkLanjut == 'y' ) {

                        cariIndex = i;

                        for (int j = cariIndex; j < jmlMhsw - 1; j++) {
                            dataMahasiswa[j] = dataMahasiswa[j + 1];
                        }

                        jmlMhsw = jmlMhsw - 1;
                    }
                }
            }

            break;

        default :
            cout << "Keyword yang anda masukan tidak valid";
            return 0;
        }

        cout << "\nApakah anda ingin ke menu utama ? (y/n) : ";
        cin >> isLanjut;
    }
    return 0;
}