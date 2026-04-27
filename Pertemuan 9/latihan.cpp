#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

// Inisialisasi queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Cek apakah queue kosong
bool isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Enqueue data
void enqueue(Queue* q, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue data
char dequeue(Queue* q) {
    if (isEmpty(q)) {
        cout << "Queue kosong" << endl;
    } else {
        Node* temp = q->front;
        q->front = q->front->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }

        cout << "Mengeluarkan data: " << temp->data << endl;
        return temp->data;
    }
}

// Tampilkan isi queue
void display(Queue* q) {
    if (isEmpty(q)) {
        cout << "Queue kosong" << endl;
    } else {
        Node* temp = q->front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Queue q, tes;
    initQueue(&q);
    initQueue(&tes);
    int jmlHuruf;
    char data, temp;

    cout << "Masukan jumlah huruf yang akan dicek : ";
    cin >> jmlHuruf;

    for (int i = 0; i < jmlHuruf; i++){
        cout << "Masukkan data: ";
        cin >> data;
        enqueue(&q, data);
    }
    
    for (int i = 0; i < jmlHuruf; i++){
        temp = dequeue(&q);
        enqueue(&tes, temp);

    }




    return 0;
}