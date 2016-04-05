#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    // sz implicitly captured by value
    wc = find_it(words.begin(), words.end(),
                 [=](const string &s)
                    { return s.size() >= sz; });
}