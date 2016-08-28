#include <iostream>
using namespace std;
int main()
{
    cout << uppercase << showbase << hex
         << "printed in hexadecimal: " << 20 << " " << 1024
         << nouppercase << noshowbase << dec << endl;
    return 0;
}