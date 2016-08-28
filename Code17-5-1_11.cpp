#include <iostream>
using namespace std;
int main()
{
    char ch;
    cin >> noskipws;    // set cin so that it read whitespace
    while (cin >> ch)
        cout << ch;
    cin >> skipws;  // reset cin to the default state so that it discards whitespace
    return 0;
}