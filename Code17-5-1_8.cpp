#include <iostream>
using namespace std;
int main()
{
    cout << 10.0 << endl;   // prints 10
    cout << showpoint << 10.0   // prints 10.0000
         << noshowpoint << endl;    // revert to default format for the decimal point
    return 0;
}