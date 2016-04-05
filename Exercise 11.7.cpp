#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    map<string, vector<string>> families;
    string famName, childName;
    while (cin >> famName) {
        cout << "Enter Children's name: " << endl;
        families[famName] = vector<string>();
        while (cin >> childName)
            families[famName].push_back(childName);
        cin.clear();
    }
    for (const auto &f : families) {
        cout << f.first << ": " << endl;
        for (const auto &c : f.second)
            cout << c << endl;
    }
    return 0;
}