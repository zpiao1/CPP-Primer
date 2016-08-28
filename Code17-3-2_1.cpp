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
    // it will repeatedly call regex_search to find all matches in file
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
        cout << it->str() << endl;  // matched word
    return 0;
}