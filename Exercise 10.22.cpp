#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using namespace std::placeholders;
bool shorterThan(const string &s, string::size_type sz);
int main()
{
    string word;
    vector<string> words;
    while (cin >> word)
        words.push_back(word);
    cout << count_if(words.begin(), words.end(), bind(shorterThan, _1, 6));
    return 0;
}
bool shorterThan(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}