#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Database {
private:
    int rollno;
    string name;
    int number;
    float percentage;

public:
    void set() {
        fstream f;
        f.open("database.txt", ios::out | ios::app);
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Number: ";
        cin >> number;
        cout << "Enter Percentage: ";
        cin >> percentage;

        f << rollno << " " << name << " " << number << " " << percentage << endl;
        f.close();
    }

    void get() {
        fstream f;
        f.open("database.txt", ios::in);
        if (!f) {
            cout << "Error opening file!" << endl;
            return;
        }
        
        cout << "Enter Roll No to retrieve: ";
        cin >> rollno;
        bool found = false;
        int roll;

        while (f >> roll) {
            f >> name >> number >> percentage;
            if (roll == rollno) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Roll No: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "Number: " << number << endl;
            cout << "Percentage: " << percentage << endl;
        } else {
            cout << "Record not found!" << endl;
        }

        f.close();
    }
};

int main() {
    Database db;
    int choice;

    do {
        cout << "1. Add record" << endl;
        cout << "2. Retrieve record" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.set();
                break;
            case 2:
                db.get();
                break;
            case 3:
                cout << "Exited" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
