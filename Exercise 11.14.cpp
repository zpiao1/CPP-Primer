#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    map<string, vector<pair<string, string>>> families;
    string famName, childName, birth;
    cout << "Enter family name: " << endl;
    while (cin >> famName) {
        cout << "Enter Children's name and birthday: " << endl;
        while (cin >> childName >> birth)
            families[famName].push_back(make_pair(childName, birth));
        cin.clear();
        cout << "Enter family name: " << endl;
    }
    for (const auto &f : families) {
        cout << f.first << ": " << endl;
        for (const auto &c : f.second)
            cout << c.first << " Birthday: " << c.second << endl;
    }
    return 0;
}