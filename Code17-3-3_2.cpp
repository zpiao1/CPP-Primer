#include <iostream>
#include <regex>
#include <string>
using namespace std;
bool valid(const smatch& m);
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    // Optional open parenthesis;
    // Three digits;
    // Optional close parenthesis;
    // Optional separator (- or . or  );
    // Three digits;
    // Optional separator (- or . or  );
    // Four digits;
    regex r(phone); // a regex to find our pattern
    smatch m;
    string s;
    // read each record from the input file
    while (getline(cin, s)) {
        // for each matching phone number
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
            // check whether the number's formatting is valid
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
    }
    return 0;
}

bool valid(const smatch& m)
{
    // if there is an open parenthesis before the area code
    if (m[1].matched)
        // the area code must be followed by a close parenthesis
        // and followed immediately by the rest of the number or a space
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        // then there can't be a close after the area code
        // the delimiters between the other two components must match
        return !m[3].matched && m[4].str() == m[6].str();
}