#include <iostream>
#include <string>
using namespace std;
int main()
{
    const string s = "Keep out!";
    for (auto &c : s) {
        cout << c << endl;
        c = 'X';
        // error: assignment for read-only reference 'c'
    }
    return 0;
}
