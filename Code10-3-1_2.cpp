#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
void elimDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);
int main()
{
    vector<string> words;
    string word;
    while (cin >> word)
        words.push_back(word);
    elimDups(words);    // put words in alphabetical order and remove duplicates
    // resort by length, maintaining alphabetical order among words of the same length
    stable_sort(words.begin(), words.end(), isShorter);
    for (const auto &s : words) // no need to copy the strings
        cout << s << " ";   // print each element separated by a space
    cout << endl;
    return 0;
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}