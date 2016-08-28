#include <iostream>
#include <random>
using namespace std;
int main()
{
    default_random_engine e;    // generates random unsigned integers
    for (size_t i = 0; i < 10; i++)
        // e() "calls" the object to produce the next random number
        cout << e() << " ";
    return 0;
}