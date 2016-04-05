#include <iostream>
#include <string>
using namespace std;
// compare the length of two strings
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}