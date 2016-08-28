#include <iostream>
#include <random>
#include <ctime>
#include <limits>
using namespace std;
unsigned unf_dist_rnd_gen(unsigned min = numeric_limits<unsigned>::min(), 
    unsigned max = numeric_limits<unsigned>::max(), unsigned seed = time(0))
{
    cout << min << ' ' << max << endl;
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}
int main()
{
    for (size_t i = 0; i < 10; ++i)
        cout << unf_dist_rnd_gen() << ' ';
    cout << endl;
    for (size_t i = 0; i < 10; ++i)
        cout << unf_dist_rnd_gen(0, 1000) << ' ';
    cout << endl;
    return 0;
}