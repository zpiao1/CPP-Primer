#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str("some string");
    // print the character in str one character to a line
    for (auto c : str)      // for every char in str
        cout << c << endl;
    return 0;
}
