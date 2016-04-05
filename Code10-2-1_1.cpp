#include <vector>
#include <numeric>
using namespace std;
int main()
{
    // sum the elements in vec starting the summation with the value 0
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    return 0;
}