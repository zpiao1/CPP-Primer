#include <string>
#include <regex>
#include <iostream>
using namespace std;
int main()
{
    // r has two subexpressions: the first is the part of the file name before the period
    // the second is the file extension
    regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
    if (regex_search(filename, results, r))
        cout << results.str(1) << endl; // print the first subexpression
    return 0;
}