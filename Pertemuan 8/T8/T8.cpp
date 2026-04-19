#include <iostream>
using namespace std;

// Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Stack berbasis linked list
struct Stack {
    Node* top;
};

// Inisialisasi stack
Stack* createStack() {
    Stack* s = new Stack;
    s->top = NULL;
    return s;
}

// Push (tambah data ke atas)
void push(Stack* s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop (ambil data teratas)
int pop(Stack* s) {
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    delete temp;
    return value;
}

// Fungsi memindahkan disk
void moveDisk(Stack* pindahDari, Stack* pindahTujuan, char dari, char tujuan) {
    int disk = pop(pindahDari);
    push(pindahTujuan, disk);
    cout << "Pindahkan batu " << disk << " dari " << dari << " ke " << tujuan << endl;
}

// Pake Rekursi untuk Menara Hanoi
void hanoi(int n, Stack* A, Stack* B, Stack* C, char dari, char sementara, char tujuan) {
    if (n == 1) {
        moveDisk(A, C, dari, tujuan);
    } else {
        hanoi(n - 1, A, C, B, dari, tujuan, sementara);
        moveDisk(A, C, dari, tujuan);
        hanoi(n - 1, B, A, C, sementara, dari, tujuan);
    }
}

int main() {
    int n = 3; //Buat rekursi

    //Buat 3 stack (Menara A, B, C)
    Stack* A = createStack();
    Stack* B = createStack();
    Stack* C = createStack();

    // Isi stack A (terbesar di bawah)
    push(A, 30);
    push(A, 20);
    push(A, 10);

    hanoi(n, A, B, C, 'A', 'B', 'C');

    return 0;
}