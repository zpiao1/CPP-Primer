#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    multimap<string, string> families;
    string famName, childName;
    while (cin >> famName >> childName)
        families.insert({famName, childName});
    for (const auto &p : families)
        cout << p.first << ' ' << p.second << endl;
    return 0;
}