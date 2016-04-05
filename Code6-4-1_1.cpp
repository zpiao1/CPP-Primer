#include <iostream>
#include <string>
using namespace std;
string read();
void print(const string &);
void print(double);         // overloads the print function
void fooBar(int ival)
{
    bool read = false;      // new scope: hides the outer declaration of read
    string s = read();      // error: read is a bool variable, not a function
    // bad practice: usually it's a bad idea to declara functions at local scope
    void print(int);        // new scope: hides previous instances of print
    print("Value: ");       // error: print(const string &) is hidden
    print(ival);            // ok: print(int) is visible
    print(3.14);            // ok: calls print(int); print(double) is hidden
}