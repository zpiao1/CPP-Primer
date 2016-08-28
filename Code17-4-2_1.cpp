#include <iostream>
#include <random>
using namespace std;
int main()
{
    default_random_engine e;    // generates unsigned random integers
    // uniformly distributed form 0 to 1 inclusive
    uniform_real_distribution<double> u(0, 1);
    for (size_t i = 0; i < 10; ++i)
        cout << u(e) << " ";
    return 0;
}