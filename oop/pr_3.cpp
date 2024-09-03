#include <iostream>
#include <string> // Include string header to use the string class
using namespace std;

class publication {
public:
    string title;
    float price;
};

class tape : public publication {
private:
    int playtime;

public:
    tape() {
        cout << "\n\n\n Tape Details:" << endl;
    }

    void invalid() {
        title = "";
        price = 0.0;
        playtime = 0;
    }

    void set() {
        cout << "\nEnter Title: ";
        cin >> title;
        cout << "Price: ";
        cin >> price;
        cout << "Enter Playtime (in minutes): ";
        cin >> playtime;

        if (title == "" || playtime < 0 || price < 0) {
            cout << "Invalid data entered. Resetting values." << endl;
            invalid();
        }
    }

    void get() {
        cout << "\nTitle: " << title;
        cout << "\nPrice: " << price;
        cout << "\nPlaytime: " << playtime << " minutes" << endl;
    }
};

class book : public publication {
private:
    int pageno;

public:
    book() {
        cout << "Book Details:" << endl;
    }

    void invalid() {
        title = "";
        price = 0.0;
        pageno = 0;
    }

    void set() {
        cout << "\nEnter Title: ";
        cin >> title;
        cout << "Price: ";
        cin >> price;
        cout << "Enter Page No: ";
        cin >> pageno;

        if (title == "" || pageno < 0 || price < 0) {
            cout << "Invalid data entered. Resetting values." << endl;
            invalid();
        }
    }

    void get() {
        cout << "\nTitle: " << title;
        cout << "\nPrice: " << price;
        cout << "\nPage No: " << pageno << endl;
    }
};

int main() {
    book b;

    b.set();
    b.get();
    tape t;

    t.set();
    t.get();

    return 0;
}
