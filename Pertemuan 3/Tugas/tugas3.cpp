#include <iostream>
using namespace std;

int main(){

    //Variabel untuk maximum array matrixnya
    int ukuranMatrix;
    
    //Sapaan selamat datang dan input variabel ukuranMatrix
    cout << "Selamat datang di program membuat matrix dan membalikannya 90 derajat\n";
    cout << "Silahkan masukan panjang matrix persegi yang diinginkan : ";
    cin >> ukuranMatrix;
    
    //Deklaras matrixnya
    int matrix [ukuranMatrix][ukuranMatrix];

    //Loop untuk input isi matrixnya
    for(int i = 0; i < ukuranMatrix; i++){
        for (int j = 0; j < ukuranMatrix; j++){
        cout << "Masukan nilai baris ke - " << (i+1) <<" Kolom ke - " << (j+1) << " : ";
        cin >> matrix[i][j];
        }
    }

    //Loop untuk mendisplay matrix yang di input sebelum diputar 
    cout << "Matriks sebelum diputar :\n";
    for(int i = 0; i < ukuranMatrix; i++){
        for (int j = 0; j < ukuranMatrix; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    //Loop untuk mendisplay matrix yang di input sesudah diputar 
    cout << "\nMatriks sesudah diputar :\n";
    for(int i = 0; i < ukuranMatrix; i++){
        for (int j = 0; j < ukuranMatrix; j++){
            cout << matrix[ukuranMatrix - 1 - j][i] << " ";
        }
        cout << endl;
    }


    return 0;
}





