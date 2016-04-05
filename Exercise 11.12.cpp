#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int main()
{
    string word;
    int count;
    vector<pair<string, int>> v;
    while (cin >> word >> count)
        v.push_back(make_pair(word, count));
    for (const auto &item : v)
        cout << item.first << ' ' << item.second << endl;
    return 0;
}