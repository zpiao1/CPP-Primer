#include <iostream>
#include <list>
#include <string>
using namespace std;
void elimDups(list<string> &words);
int main()
{
    string word;
    list<string> words;
    while (cin >> word)
        words.push_back(word);
    elimDups(words);
    for (const auto &s : words)
        cout << s << ' ';
    cout << endl;
    return 0;
}
void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}