#include <regex>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cmatch results; // will match character array input sequences
    if (regex_search("myfile.cc", results, r))
        cout << results.str() << endl;  // print the current match
    return 0;
}