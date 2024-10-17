#include <iostream>
using namespace std;
struct Stack
{
    char data[50];
    int top;
};
struct Stack s;

void create(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (s.top != 50)
        {
            s.top++;
            s.data[s.top] = str[i];
        }
    }
}

string reverse()
{
    string str;
    if (s.top == -1)
    {
        cout << "No data found" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            str += s.data[i];
        }
    }
    return str;
}

void isPalindrome(string str)
{
    create(str);

    string reverseStr = reverse();
    if (reverseStr == str)
    {
        cout << "String is palindrome" << endl;
    }
    else
    {
        cout << "String is not palindrome" << endl;
    }
}
int main()
{
    string str;
    cout << "Enter a string";
    cin >> str;
    s.top = -1;
    int ch;
    do
    {
        cout << "\n\nMenu \n1.Show Reverse String \n 2.Check is palindrome or not 3.any other key to exit" << endl;
        cin >> ch;
        if (ch == 1)
        {
            create(str);

            cout << "Reverse string:" << reverse() << endl;
        }
        else if (ch == 2)
        {
            isPalindrome(str);
        }
        else
        {
            break;
        }

    } while (true);
}