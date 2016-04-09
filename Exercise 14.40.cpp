#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Shorter {
    bool operator()(const string &a, const string &b) {
        return a.size() < b.size();
    }
};
class AtLeastSz {
public:
    bool operator()(const string &a) {
        return a.size() >= sz;
    }
    AtLeastSz(size_t size):
        sz(size) {}
private:
    size_t sz;
};
struct PrintString {
    void operator()(const string &s) {
        cout << s << " ";
    }
};
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), Shorter());
    auto wc = find_if(words.begin(), words.end(), AtLeastSz(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), PrintString());
    cout << endl;
}