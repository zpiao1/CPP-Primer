#include <iostream>
#include <string>
#include <regex>
using namespace std;
using namespace std::regex_constants;
int main()
{
    string zip_code = "(\\d{5})(-)?(\\d{4})";
    string fmt = "$1-$3 ";
    string s;
    regex r(zip_code);
    while (getline(cin, s))
        cout << regex_replace(s, r, fmt, format_no_copy) << endl;
    return 0;
}