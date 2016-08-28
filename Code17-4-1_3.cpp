#include <iostream>
#include <random>
using namespace std;
int main()
{
    default_random_engine e;
    cout << "min: " << e.min() << " max: " << e.max() << endl;
    return 0;
}