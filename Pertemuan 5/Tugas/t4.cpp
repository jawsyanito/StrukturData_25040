#include <iostream>
using namespace std;

//Node pakai struct yang isinya angka (Doubly Linked List)
struct Node {
    int angka;
    Node* next; //Pointer untuk ke node selanjutnya
    Node* prev; //Pointer untuk ke node sebelumnya
};

//Deklarasi pointer globalnya
Node *awal = NULL, *akhir = NULL, *inputAngka = NULL;

int main () {
    int banyakAngka;

    cout << "Ada berapa angka yang ingin anda simpan ? : ";
    cin >> banyakAngka;

    //Loop untuk input nilai yang akan dimasukan ke linkedlistnya 
    //sesuai banyak angka yang sudah di input
    
    for (int i = 0; i < banyakAngka; i++){
        //Buat node baru setiap loop
        inputAngka = new Node;

        cout << "Masukan angka ke - " << (i+1) << " : ";
        cin >> inputAngka->angka;

        inputAngka->next = NULL;
        inputAngka->prev = NULL;

        if (awal == NULL){
            awal = inputAngka;
            akhir = inputAngka;
        }
        else{
            //Nyambung listnya jika kondisi terpenuhi
            akhir->next = inputAngka;
            inputAngka->prev = akhir;
            akhir = inputAngka;
        }
    }

    cout << "\nData yang tersimpan:\n";
    //Loop untuk nampilin data sebelum di reverse
    Node* tampil = awal;
    while(tampil != NULL){
        cout << tampil->angka;
        if(tampil->next != NULL){
            cout << " -> ";
        }
        tampil = tampil->next;
    }
    
    //Node buat reversenya
    Node* current = awal;
    Node* temp = NULL;
    
    //Buat reverse data dengan tukar arah pointer prev dan next
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    //Ganti nilai awal 
    if(temp != NULL){
        awal = temp->prev;
    }
    
    cout << "\nData yang dibalik:\n";
    //Loop buat nampilin data yang telah di reverse
    tampil = awal;
    while(tampil != NULL){
        cout << tampil->angka;
        if(tampil->next != NULL){
            cout << " -> ";
        }
        tampil = tampil->next;
    }
    
    return 0;
}