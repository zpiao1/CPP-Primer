#include <iostream>
#include <string>
#include <regex>
using namespace std;
using namespace std::regex_constants;
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string fmt = "$2.$5.$7";
    string s;
    regex r(phone);
    while (getline(cin, s))
        cout << regex_replace(s, r, fmt, format_first_only | format_no_copy) << endl;
    return 0;
}