#include <iostream>
#include <string>
using namespace std;
int main()
{
    string line;
    // read input a line at a time and discard blank lines
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return 0;
}
