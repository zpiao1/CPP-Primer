#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s("some thing");
    // process character in s until we ran out of characters or we hit a whitespace
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // capitalize the current character
    cout << s << endl;
    return 0;
}
