#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s("Hello world!!!");
    // punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
    decltype(s.size()) punct_cnt = 0;
    // string::size_type punct_cnt = 0;
    // count the number of punctuation characters in s
    for (auto c : s)        // for every c in s
    // for (char c : s)
        if (ispunct(c))     // if the character is punctuation
            ++punct_cnt;    // increment the punctuation counter
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
    return 0;
}
