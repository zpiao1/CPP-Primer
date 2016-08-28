#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    // one or more alphanumeric charaters followed by a '.' followed by "cpp" or "cxx" or "cc"
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results;
    string filename;
    while (cin >> filename)
        if (regex_search(filename, results, r))
            cout << results.str() << endl;  // print the current match
    return 0;
}