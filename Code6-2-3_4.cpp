#include <iostream>
#include <string>
using namespace std;
string::size_type find_char(const string &s, char c, string::size_type &occurs);
bool is_setence(const string &s)
{
    // if there's a single period at the end of s, then s is a sentence
    string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}