#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (auto ch : s)
        if (!ispunct(ch))
            cout << ch;
    cout << endl;
    return 0;
}
