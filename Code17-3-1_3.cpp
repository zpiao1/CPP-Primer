#include <iostream>
#include <exception>
#include <stdexcept>
#include <regex>
using namespace std;
int main()
{
    try {
        // error: missing close bracket after alnum; the constructore will throw
        regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    } catch (regex_error e) {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    return 0;
}