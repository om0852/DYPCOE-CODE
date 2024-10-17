#include <iostream>
using namespace std;
#define MAX 5

class Pizza {
public:
    int arr[MAX];
    int rear = -1;
    int front = -1;

    void insert() {
        int data;
        cout << "Enter Data: ";
        cin >> data;

        if ((rear + 1) % MAX == front) {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }
        
        rear = (rear + 1) % MAX;
        arr[rear] = data;
        cout << "Inserted: " << data << endl;
    }

    void Delete() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
};

int main() {
    Pizza q;
    int ch;

    do {
        cout << "\nMenu \n1. Insert \n2. Delete \n3. Press any other key to exit" << endl;
        cout << "Enter a choice: ";
        cin >> ch;

        if (ch == 1) {
            q.insert();
        } else if (ch == 2) {
            q.Delete();
        } else {
            break;
        }
    } while (ch <= 2);

    return 0;
}
