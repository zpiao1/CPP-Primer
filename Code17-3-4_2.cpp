#include <iostream>
#include <string>
#include <regex>
using namespace std;
using namespace std::regex_constants;
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone); // a regex to find our pattern
    smatch m;
    string s;
    string fmt = "$2.$5.$7";    // reformat numbers to ddd.ddd.dddd
    // generate just the phone numbers: use a new format string
    string fmt2 = "$2.$5.$7 ";  // put space after the last number as a separator
    // read each record from the input file
    while (getline(cin, s)) {
        cout << regex_replace(s, r, fmt) << endl;
        // tell regex_replace to copy only the text that it replaces
        cout << regex_replace(s, r, fmt2, format_no_copy) << endl;
    }
    return 0;
}