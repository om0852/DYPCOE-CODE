#include <iostream>
#define MAX 5
using namespace std;
class Queue
{
public:
    int arr[MAX];
    int rear = -1;
    int front = -1;

    void push_back()
    {
        int data;
        cout << "Enter Data";
        cin >> data;
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1)
        {
            cout << "Can't Insert" << endl;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pop_back()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else if (rear < front)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Delete Element" << arr[rear];
            rear--;
        }
    }

    void push_front()
    {
        int data;
        cout << "Enter Data";
        cin >> data;

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }
    void pop_front()
    {
        if (front == -1)
        {
            cout << "Queue is empty";
        }
        else
        {
            cout << "Delete Element" << arr[front];

            front++;
        }
    }
};
int main()
{
    Queue q;
    int ch;

    do
    {
        cout << "\n Menu \n 1.Insert at end \n 2.Delete at end \n 3.Insert at front \n 4.Delete at front \n 5.Press any other key to exit" << endl;
        cout << "Enter choice:";
        cin >> ch;

        if (ch == 1)
        {
            q.push_back();
        }
        else if (ch == 2)
        {
            q.pop_back();
        }
        else if (ch == 3)
        {
            q.push_front();
        }
        else if (ch == 4)
        {
            q.pop_front();
        }
        else
        {
            break;
        }
    } while (ch <= 4);

    return 0;
}