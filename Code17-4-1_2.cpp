#include <iostream>
#include <random>
using namespace std;
int main()
{
    // uniformly distributed from 0 to 9 inclusive
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e;    // generates unsigned random integers
    for (size_t i = 0; i < 10; i++)
        // u uses e as a source of numbers
        // each call returns a uniformly distributed value in the specified range
        cout << u(e) << " ";
    return 0;
}