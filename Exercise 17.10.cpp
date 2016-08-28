#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    cout << "       1098765432109876543210" << endl;
    bitset<22> bits1("1000000010000100101110");
    cout << "bits1: " << bits1 << endl;
    bitset<22> bits2;
    size_t i = 1, j = 2;
    do {
        bits2.set(i);
        j += i;
        i = j - i;
    } while (i <= 21);
    cout << "bits2: " << bits2 << endl;
    return 0;
}