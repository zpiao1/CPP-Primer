#include <iostream>
#include <string>
using namespace std;
void reset(int &i);
void reset(int *ip);
string::size_type find_char(const string &s, char c, string::size_type &occurs);
int main()
{
    int i = 0;
    const int ci = i;
    string::size_type ctr = 0;
    reset(&i);      // calls the version of reset that has an int* parameter
    reset(&ci);     // error: can't initialize an int* from a pointer to a const int object
    reset(i);       // calls the version of reset that has an int& parameter
    reset(ci);      // error: can't bind a plain reference to the const object ci
    reset(42);      // error: can't bind a plain reference to a literal
    reset(ctr);     // error: types don't match; ctr has an unsigned type
    // ok: find_char's first parameter is a reference to const
    find_char("Hello world!", 'o', ctr);
}