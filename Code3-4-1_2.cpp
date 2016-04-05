#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s("some string");
    if (s.begin() != s.end()) { // make sure s is not empty
        auto it = s.begin();    // it denotes the first character in s
        *it = toupper(*it);     // make that character uppercase
    }
    cout << s << endl;
    return 0;
}
