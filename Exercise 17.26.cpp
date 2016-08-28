#include <iostream>
#include <string>
#include <regex>
using namespace std;
using namespace std::regex_constants;
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string fmt = "$2.$5.$7 ";
    string s;
    regex r(phone);
    while (getline(cin, s)) {
        size_t i = 0;
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
            if (i++ == 0) // The first match of phone, ignored
                continue;
            cout << it->format(fmt);
        }
        cout << endl;
    }
    return 0;
}