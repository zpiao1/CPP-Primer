#include <iostream>
#include <random>
using namespace std;
unsigned unf_dist_rnd_gen()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u;
    return u(e);
}
int main()
{
    for (size_t i = 0; i < 10; ++i)
        cout << unf_dist_rnd_gen() << endl;
    return 0;
}