#include <iostream>
#include <vector>
#include <random>
using namespace std;
// almost surely the wrong way to generate a vector of random integers
// output from this function will be the same 100 numbers on every call!
vector<unsigned> bad_randVec()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; i++)
        ret.push_back(u(e));
    return ret;
}
// returns a vector of 100 uniformly distributed random numbers
vector<unsigned> good_randVec()
{
    // because engines and distributions retain state, they usually should be
    // defined as static so that new numbers are generated on each call
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}
int main()
{
    vector<unsigned> v1(bad_randVec());
    vector<unsigned> v2(bad_randVec());
    // will print equal
    cout << ((v1 == v2) ? "equal" : "not equal") << endl;
    return 0;
}