#include <random>
#include <iostream>
using namespace std;
int main()
{
    default_random_engine e1;   // uses the default seed
    default_random_engine e2(2147483646);   // use the given seed value
    // e3 and e4 will generate the same sequence because they use the same seed
    default_random_engine e3;   // uses the default seed
    e3.seed(32767);             // call seed to set a new seed value
    default_random_engine e4(32767);    // set the seed value to 32767
    for (size_t i = 0; i != 100; ++i) {
        if (e1() == e2())
            cout << "unseeded match at iteration: " << i << endl;
        if (e3() != e4())
            cout << "seeded differs at iteration: " << i << endl;
    }
    return 0;
}