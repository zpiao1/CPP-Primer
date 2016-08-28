#include <ctime>
#include <random>
using namespace std;
int main()
{
    default_random_engine e1(time(0));  // a somewhat random seed
    return 0;
}