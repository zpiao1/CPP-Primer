#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string file("receipt freind theif receive");
    string pattern("[^c]ei");
    // we want the whole word in which our pattern appears
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase); // we'll ignore case in doing the match
    // same for loop header as before
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
        auto pos = it->prefix().length();   // size of the prefix
        pos = pos > 40 ? pos - 40 : 0;      // we want up to 40 characters
        cout << it->prefix().str().substr(pos)  // last part of the prefix
             << "\n\t\t>>> " << it->str() << " <<<\n"   // matched word
             << it->suffix().str().substr(0, 40);       // first part of the suffix
             << endl;
    }

    return 0;
}