#include <iostream>
#include <string>
#include <regex>
using namespace std;
bool valid(const smatch& m);
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-.]|| *)?(\\d{3})([-.]|| *)?(\\d{4})";
    // Optional open parenthesis
    // Three digits
    // Optional close parenthesis
    // Optional '-' or '.' or any number of ' '
    // Three digits
    // Optional '-' or '.' or any number of ' '
    // Four digits
    regex r(phone);
    smatch m;
    string s;
    while (getline(cin, s)) {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) 
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
    }
}

bool valid(const smatch& m)
{
    if (m[1].matched)
        // First subexpression is '(', so the third subexpression should be ')' and 
        // the next should be empty or spaces only
        return m[3].matched && (!m[4].matched 
            || m[4].str().find_first_not_of(' ') == string::npos);
    else
        // First subexpression is not '(', so the third subexpression should not be
        // ')' and the delimiters should either be the same or both contain only
        // spaces
        return !m[3].matched && (m[4].str() == m[6].str() 
            || (m[4].str().find_first_not_of(' ') == string::npos 
                && m[6].str().find_first_not_of(' ') == string::npos));
}