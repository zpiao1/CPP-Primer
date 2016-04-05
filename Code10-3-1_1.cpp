#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void elimDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);
int main()
{
    vector<string> words;
    sort(words.begin(), words.end(), isShorter);
    return 0;
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end(), isShorter);
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}
// comparison functinos to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}