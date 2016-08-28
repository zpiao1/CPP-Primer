#include <random>
using namespace std;
int main()
{
    // empty <> signify we want to use the default result type
    uniform_real_distribution<> u(0, 1);    // generates double by default
    return 0;
}