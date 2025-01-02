#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PersonalRecord
{

public:
    string name;
    int dob;

    PersonalRecord(string n, int d)
    {
        name = n;
        dob = d;
    }
};

bool Compare(PersonalRecord p1, PersonalRecord p2)
{
    return p1.name < p2.name;
}
int main()
{
    vector<PersonalRecord> record;
    PersonalRecord p1("om", 12);
    PersonalRecord p2("yash", 14);
    PersonalRecord p3("amit", 14);
    record.push_back(p1);
    record.push_back(p2);
    record.push_back(p3);
    string name;
    int ch;
    do
    {
        cout << "\nMenu\n1.Sort the list\n 2.serach by name\n 3.display \n Press any other key to exit";
        cin >> ch;
        if (ch == 1)
        {
            sort(record.begin(), record.end(), Compare);
        }
        else if (ch == 2)
        {
            cout << "Enter the name:";
            cin >> name;
            for (auto r : record)
            {
                if (r.name == name)
                {
                    cout << "Record found\n";
                    break;
                }
            }
        }
        else if (ch == 3)
        {
            for (auto r : record)
            {
                cout << r.name << endl;
            }
        }
        else
        {
            break;
        }
    } while (ch <= 3);

    return 0;
}