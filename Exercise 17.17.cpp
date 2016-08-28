#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string file("receipt freind theif receive");
    string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    regex r(pattern, regex::icase);
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) 
        cout << it->str() << endl;
    return 0;
}