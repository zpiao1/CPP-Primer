#include <iostream>
#include <random>
#include <ctime>
using namespace std;
unsigned unf_dist_rnd_gen(unsigned seed = time(0))
{
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u;
    return u(e);
}
int main()
{
    for (size_t i = 0; i < 10; ++i)
        cout << unf_dist_rnd_gen() << ' ';
    cout << endl;
    for (size_t i = 0; i < 10; ++i)
        cout << unf_dist_rnd_gen(32767) << ' ';
    cout << endl;
    return 0;
}