#include <iostream>
using namespace std;

struct Queue {
    int data[50];
    int rear = -1;
    int front = -1;
};

void insert(Queue* q) {
    int data;
    cout << "Enter Data: ";
    cin >> data;

    if (q->rear == -1 && q->front == -1) {
        q->rear = 0;
        q->front = 0;
    } 
    else if (q->rear == 49) {
        cout << "Queue is full" << endl;
        return;
    } 
    else {
        q->rear++;
    }
    q->data[q->rear] = data;
}

void Delete(Queue* q) {
    if (q->rear == -1 && q->front == -1) {
        cout << "Queue is empty" << endl;
        return;
    } 
    else if (q->front > q->rear) {
        cout << "Queue is empty" << endl;
    } 
    else {
        cout << "Deleted Element: " << q->data[q->front] << endl;
        q->front++;
    }
}

int main() {
    Queue q;
    int ch;

    do {
        cout << "\nMenu\n1. Insert\n2. Delete\n3. Press any other key to exit" << endl;
        cin >> ch;

        if (ch == 1) {
            insert(&q);
        } 
        else if (ch == 2) {
            Delete(&q);
        } 
        else {
            break;
        }
    } while (true);

    return 0;
}
