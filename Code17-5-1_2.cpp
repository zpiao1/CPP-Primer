#include <iostream>
using namespace std;
int main()
{
    bool bool_val = get_status();
    cout << boolalpha   // sets the internal state of cout
         << bool_val
         << noboolalpha;    // resets the internal state to default formatting
    return 0;
}