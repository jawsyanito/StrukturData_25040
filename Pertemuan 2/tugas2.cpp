#include <iostream>
using namespace std;

int main() {
    char alfabet[] = {'a','a','a','a','b','b','c','c'};
    char ujiCharSama;
    int panjangArrBaru = 0;
    int n = 8;
    
    for(int i = 0;i < n;){
        int hitungCharSama = 0;
        ujiCharSama = alfabet[i];

        //Loop buat itung char yang sama
       while (i < n && alfabet[i] == ujiCharSama){
            hitungCharSama++;
            i++;
        }
        
        alfabet[panjangArrBaru++] = ujiCharSama; //Mengisi array dengan char uji

        //Mengganti isi array ketika ada char yang sama
        if (hitungCharSama > 1) {
            alfabet[panjangArrBaru++] = hitungCharSama + '0';
        }
    }
    //Loop untuk menampilkan array dengan panjang baru
    for (int i = 0; i < panjangArrBaru ;i++){
        cout << alfabet[i];
    }
    return 0;
}