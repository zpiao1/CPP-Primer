#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void biggies(vector<string> &words,
             vector<string>::size_type sz,
             ostream &os = cout, char c = ' ')
{
    // code to reorder words as before
    // statement to print cout revised to print to os
    for_each(words.begin(), words.end(),
             [&os, c](const string &s), { os << s << c; });
}