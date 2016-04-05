#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;
void biggies(vector<string> &words,
             vector<string>::size_type sz);
bool compSize(const string &a, const string &b);
bool check_size(const string &a, string::size_type sz);
ostream &print(ostream &os, const string &s, char c);
int main()
{
    string word;
    vector<string> words;
    while (cin >> word)
        words.push_back(word);
    biggies(words, 6);
    return 0;
}
void biggies(vector<string> &words,
             vector<string>::size_type sz)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
    stable_sort(words.begin(), words.end(), bind(compSize, _1, _2));
    auto true_end = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    auto count = true_end - words.begin();
    cout << count << ' ' << (count > 1 ? string("words") : string("word"))
         << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), true_end, bind(print, ref(cout), _1, ' '));
    cout << endl;
}
bool compSize(const string &a, const string &b)
{
    return a.size() < b.size();
}
bool check_size(const string &a, string::size_type sz)
{
    return a.size() >= sz;
}
ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}