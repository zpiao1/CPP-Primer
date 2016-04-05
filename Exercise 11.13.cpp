#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int main()
{
    string word;
    int count;
    vector<pair<string, int>> v1, v2, v3;
    while (cin >> word >> count) {
        v1.push_back(make_pair(word, count));
        v2.push_back(pair<string, int>(word, count));
        v3.push_back({word, count});
    }
    cout << "v1: " << endl;
    for (const auto &item : v1)
        cout << item.first << ' ' << item.second << endl;
    cout << "v2: " << endl;
    for (const auto &item : v2)
        cout << item.first << ' ' << item.second << endl;
    cout << "v3: " << endl;
    for (const auto &item : v3)
        cout << item.first << ' ' << item.second << endl;
    return 0;
}