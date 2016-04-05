#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
        throw runtime_error("b is 0!\n");
    return 0;
}