#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s("Hello world!!!");
    // convert s to uppercase
    for (auto &c : s)        // for every c in s (note: c is a reference)
        c = toupper(c);     // c is a reference, so the assignment changes the char in s
    cout << s << endl;
    return 0;
}
