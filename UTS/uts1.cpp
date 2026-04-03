#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi konversi biner ke desimal
int konversiBiner(Node* head) {
    int total = 0;
    int posisi = 1;
    Node* current = head;

    while (current != NULL) {
        total += current->data * posisi;
        posisi *= 2;
        current = current->next;
    }
    return total;
}

int main() {
    //Inisiasi awal head adalah null
    Node* head = NULL;
    int jumlahBit, bit;

    //Input bit dan jumlah bit
    cout << "Masukkan jumlah bit: ";
    cin >> jumlahBit;

    cout << "Masukkan nilai bit (0 atau 1):\n";
    for (int i = 0; i < jumlahBit; i++) {
        cin >> bit;

        //Akan memberhentikan program jika input bukan 1 atau 0
        if (bit != 0 && bit != 1 ) {
            cout << "Mohon masukan 0/1 saja";
            return 0;
        }

        //Membuat node baru sambil mengisinya
        Node* newNode = new Node;
        newNode->data = bit;
        newNode->next = NULL;

        //Pakai temp buat nyambung node baru 
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
        temp->next = newNode;
        }
    }

    int hasil = konversiBiner(head);

    cout << "Nilai desimal: " << hasil << endl;

    return 0;
}