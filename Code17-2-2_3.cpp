#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    bitset<16> bits;
    cin >> bits;    // read up to 16 1 or 0 characters from cin
    cout << "bits: " << bits << endl;   // print what we just read
    return 0;
}