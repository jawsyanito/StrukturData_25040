#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

struct stack{
    node* top;
    stack(){
        top = NULL;
    }
    void push(int value){
        node* newnode = new node;
        newnode ->data = value;
        newnode ->next = top;
        top = newnode;
    }

    void pop(){
        node* temp = top;
        int poppedvalue = top ->data;
        top = top->next;
        delete temp;
    }
    
};


int main() {
    stack A, B ,C;

    A.push(30);
    A.push(20);
    A.push(10);

    while (true) {
        if (A.top )

        
    }

    return 0;
}





