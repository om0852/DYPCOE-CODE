#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node *next;
};

Node *head1 = NULL;
Node *head2 = NULL;
int count1 = 0;
int count2 = 0;

void insert(int data, string name1, int position, Node*& head, string post, int &total) {
    Node *newNode = new Node();
    newNode->prn = data;
    newNode->name = name1;
    newNode->next = NULL;
    
    if (post == "P") {
        newNode->next = head;
        head = newNode;
        total++;
    }
    else if (post == "M") {
        if (head == NULL) {
            cout << "First add president.\n";
            return;
        }
        Node* temp = head;
        int count = 0;
        
        if (position <= 0) {
            newNode->next = head->next;
            head->next = newNode;
            total++;
        } 
        else if (position >= total) {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            total++;
        } 
        else {
            while (count < position - 1 && temp->next != NULL) {
                temp = temp->next;
                count++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            total++;
        }
    }
    else if (post == "S") {
        if (head == NULL) {
            cout << "First add president.\n";
            return;
        }
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        total++;
    }
}

void deleteMember(int prn, Node*& head, int &total) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->prn == prn) {
        head = temp->next;
        delete temp;
        total--;
        return;
    }
    while (temp != NULL && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Member not found.\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    total--;
}

void display(Node* head) {
    Node *temp = head;
    if (head == NULL) {
        cout << "Empty\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->name << " (" << temp->prn << ") -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int ch, div, no, pos;
    string name;
    do {
        cout << "\nSelect division\n1. A division\n2. B division\nPress any other key to exit\n";
        cin >> div; 
        if (div != 1 && div != 2) break;
        
        do {
            cout << "\nMenu\n1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete Member\n5. Display\n6. Total Count\n7. Exit\n";
            cin >> ch;
            if (ch == 7) break;
            if (ch < 1 || ch > 7) {
                cout << "Invalid choice.\n";
                continue;
            }

            if (ch != 5 && ch != 6 && ch != 4) {
                cout << "Enter PRN No: ";
                cin >> no;
                cout << "Enter name of student: ";
                cin >> name;
            }
            
            switch (ch) {
                case 1:
                    if (div == 1) insert(no, name, 0, head1, "P", count1);
                    else insert(no, name, 0, head2, "P", count2);
                    break;
                case 2:
                    if (div == 1) insert(no, name, -1, head1, "S", count1);
                    else insert(no, name, -1, head2, "S", count2);
                    break;
                case 3:
                    cout << "Enter position: ";
                    cin >> pos;
                    if (div == 1) insert(no, name, pos, head1, "M", count1);
                    else insert(no, name, pos, head2, "M", count2);
                    break;
                case 4:
                    cout << "Enter PRN to delete: ";
                    cin >> no;
                    if (div == 1) deleteMember(no, head1, count1);
                    else deleteMember(no, head2, count2);
                    break;
                case 5:
                    if (div == 1) display(head1);
                    else display(head2);
                    break;
                case 6:
                    if (div == 1) cout << "Total count: " << count1 << endl;
                    else cout << "Total count: " << count2 << endl;
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (ch != 7);
    } while (div == 1 || div == 2);
    
    return 0;
}
