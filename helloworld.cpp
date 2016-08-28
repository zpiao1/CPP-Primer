#include <string>
#include <iostream>
#include <functional>

using namespace std;
int main()
{
    int a = 1;
    string s = "hey!";

    int b = std::move(a);
    cout << b << endl;
    b = std::move(a);
    cout << b << endl;

    string t = std::move(s);
    cout << t << endl;
    t = std::move(s);
    cout << t << endl;
    return 0;
}