#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v2;     // empty vector
    for (int i = 0; i != 100; ++i)
        v2.push_back(i);        // append sequential integers to v2
    // at end of loop v2 has 100 elements, value 0 ... 99
    return 0;
}
