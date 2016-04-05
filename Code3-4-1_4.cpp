#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int>::iterator it;           // it can read and write vector<int> elements
    string::iterator it2;               // it2 can read and write characters in a string
    vector<int>::const_iterator it3;    // it3 can read but not write elements
    string::const_iterator it4;         // it4 can read but not write characters
    return 0;
}
