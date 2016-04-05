#include <iostream>
using namespace std;
int main()
{
    int a = 3, b = 5;
    auto f = [a](int b) -> int
             { return a + b; };
    cout << f(b) << endl;
    return 0;
}