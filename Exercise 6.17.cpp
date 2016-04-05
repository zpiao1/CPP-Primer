#include <iostream>
#include <string>
#include <cctype>
#include "Chapter6.h"
using namespace std;
int main()
{
    string s("Hello world!");
    cout << containCaps(s) << endl;
    strToLower(s);
    cout << s << endl;
}

bool containCaps(const string &s)
{
    for (auto ch : s)
        if (isupper(ch))
            return true;
    return false;
}

void strToLower(string &s)
{
    for (auto &ch : s)
        ch = tolower(ch);
}