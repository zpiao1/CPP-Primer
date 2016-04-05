#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    vector<int> ivec = {1,3,5,7,8,15};
    auto sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << sum << endl;
    return 0;
}