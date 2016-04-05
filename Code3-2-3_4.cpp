#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s("some string");
    if (!s.empty())             // make sure there's a character to print
        cout << s[0] << endl;   // print the first character in s
    for (decltype(s.size()) index = 0;
         index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);   // capitalize the current character
    cout << s << endl;
    return 0;
}
