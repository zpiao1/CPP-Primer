#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    vector<char> cvec{'H','e','l','l','o'};
    string s(cvec.cbegin(), cvec.cend());
    cout << s << endl;
    return 0;
}