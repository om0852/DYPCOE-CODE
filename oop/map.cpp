#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> stateData = {
        {"Maharashtra", 112374333},
        {"Gujarat", 60439692},
        {"Rajasthan", 68548437},
        {"Karnataka", 61095297},
        {"Punjab", 27743338}};
    string data;
    cout << "Enter State:";
    cin >> data;
    for (auto i = stateData.begin(); i != stateData.end(); ++i)
    {
        if (i->first == data)
        {
            cout << "State:" << i->first << " " << "population" << i->second << endl;
        }
    }

    return 0;
}