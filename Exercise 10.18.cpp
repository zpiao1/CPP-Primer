#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void biggies(vector<string> &words, vector<string>::size_type sz);
void elimDups(vector<string> &words);
string make_plural(size_t count, string s, const string &suffix);
int main()
{
    string word;
    vector<string> words;
    while (cin >> word)
        words.push_back(word);
    biggies(words, 5);
    return 0;
}
string make_plural(size_t count, string s, const string &suffix)
{
    return (count > 1 ? s + suffix : s);
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                                              { return a.size() < b.size(); });
    auto true_end = partition(words.begin(), words.end(), [sz](const string &s)
                                                         { return s.size() >= sz; });
    auto count = true_end - words.begin();
    cout << count << ' ' << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), true_end, [](const string &s)
                                   { cout << s << ' '; });
    cout << endl;
}
