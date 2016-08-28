#include <iostream>
using namespace std;
int main()
{
    cout << showbase;   // show the base when printing integral values
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "in octal: " << oct << 20 << " " << 1024 << endl;
    cout << "in hex: " << hex << 20 << " " << 1024 << endl;
    cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase; // reset the state of the stream
    return 0;
}