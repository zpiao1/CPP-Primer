#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    decltype(s.size()) index = 0;
    cin >> s;
    while (index < s.size())
        s[index++] = 'X';
    cout << s << endl;
    return 0;
}
