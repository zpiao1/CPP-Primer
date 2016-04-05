#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> vec;    // empty vector
    auto it = back_inserter(vec);   // assigning through it adds elements to vec
    *it = 42;   // vec now has one element with value 42;
    return 0;
}