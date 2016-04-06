#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
};
int main()
{
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b) {
                    return a.size() < b.size();
                });
    stable_sort(words.begin(), words.end(), ShorterString());
    return 0;
}