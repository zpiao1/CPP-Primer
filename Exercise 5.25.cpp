#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    try {
        if (b == 0)
            throw runtime_error("b is 0!\n");
        cout << a / b << endl;
    } catch (runtime_error err) {
        cout << err.what();
    }
    return 0;
}