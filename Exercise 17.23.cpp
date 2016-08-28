#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string zip_code = "(\\d{5})(-)?(\\d{4})?";
    // 5 digits + Optional '-' + Optional 4 digits
    regex r(zip_code);
    string s;
    while (getline(cin, s))
        for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it)
            if (!(*it)[2].matched || (*it)[3].matched)
                cout << it->str() << endl;
    return 0;
}