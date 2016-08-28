#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results; // will match a string input sequence, but not char*
    if (regex_search("myfile.cc", results, r))  // error: char* input
        cout << results.str() << endl;
    return 0;
}