#include <iostream>
#define maks 20 // maksimum data pada queue
using namespace std;

// deklarasi struct queue
struct Queue {
    int front = 0;
    int rear = 0;
    int data[maks];
} Q;

// cek apakah queue penuh
bool isFull() {
    return Q.rear == maks;
}

// cek apakah queue kosong
bool isEmpty() {
    return Q.rear == 0;
}

// menampilkan queue
void printQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Queue : ";
        for (int i = Q.front; i < Q.rear; i++) {
            cout << Q.data[i];
            if (i != Q.rear - 1) cout << " -> ";
        }
        cout << endl;
    }
}

// enqueue
void enqueue() {
    if (isFull()) {
        cout << "Queue penuh" << endl;
    } else {
        int data;
        cout << "Masukkan Data : ";
        cin >> data;

        Q.data[Q.rear] = data;
        Q.rear++;

        cout << "Data Ditambahkan" << endl;
        printQueue();
    }
}

// dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Kosong" << endl;
    } else {
        cout << "Mengeluarkan Data : " << Q.data[Q.front] << endl;

        // menggeser semua data ke head
        for (int i = Q.front; i < Q.rear - 1; i++) {
            Q.data[i] = Q.data[i + 1];
        }

        Q.rear--;
        printQueue();
    }
}

int main() {
    int pilih;

    do {
        cout << "\nMenu Pilihan\n";
        cout << "-----------------\n";
        cout << "[1] Enqueue\n";
        cout << "[2] Dequeue\n";
        cout << "[3] Keluar\n";
        cout << "-----------------\n";
        cout << "Masukkan pilihan : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                break;
            default:
                cout << "Pilihan tidak tersedia\n";
        }

    } while (pilih != 3);

    return 0;
}

