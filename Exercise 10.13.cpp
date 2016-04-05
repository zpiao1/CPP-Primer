#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool longerThan5(const string &s);
int main()
{
    string word;
    vector<string> words;
    while (cin >> word)
        words.push_back(word);
    auto end = partition(words.begin(), words.end(), longerThan5);
    for (auto iter = words.begin(); iter != end; ++iter)
        cout << *iter << ' ';
    cout << endl;
    return 0;
}

bool longerThan5(const string &s)
{
    return s.size() >= 5;
}