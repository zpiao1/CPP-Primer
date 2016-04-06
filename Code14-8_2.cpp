#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '):
        os(o), sep(c) {}
    void operator()(const string &s) const {
        os << s << sep;
    }
private:
    ostream &os;    // stream on which to write
    char sep;       // character to print after each output
};
int main()
{
    PrintString printer;    // uses the defaults; prints to cout
    printer(s);             // prints s followed by a space on cout
    PrintString errors(cerr, '\n');
    errors(s);              // prints s followed by a newline on cerr
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
    return 0;
}