#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    // g is a callable object that takes two arguments
    auto g = bind(f, a, b, _2, c, _1);
    // sort on word length, shortest to longest
    sort(words.begin(), words.end(), isShorter);
    // sort on word length, longest to shortest
    sort(words.begin(), words.end(), bind(isShorter, _2, _1));
    // os is a local variable referring to an output stream
    // c is a local variable of type char
    for_each(words.begin(), words.end(), 
             [&os, c](const string &s) { os << s << c; });
    // error: cannot copy os
    for_each(words.begin(), words.end(), bind(print, os, _1, ' '));
    return 0;
}
ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}