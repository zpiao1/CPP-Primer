#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    // Optional '(' + 3 digits + Optional ')' + Optional '-' or '.' or ' ' +
    // 3 digits + Optional '-' or '.' or ' ' + 4 digits
    string fmt = "$2.$5.$7";    // reformat numbers to ddd.ddd.dddd
    regex r(phone); // a regex to find our pattern
    string number = "(908) 555-1800";
    cout << regex_replace(number, r, fmt) << endl;
    return 0;
}