#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void elimDups(vector<string> &word);
int main()
{
    string word;
    vector<string> words;
    while (cin >> word)
        words.push_back(word);
    elimDups(words);
    for (const auto &s : words)
        cout << s << ' ';
    cout << endl;
    return 0;
}
void elimDups(vector<string> &word)
{
    sort(word.begin(), word.end());
    auto end_unique = unique(word.begin(), word.end());
    word.erase(end_unique, word.end());
}