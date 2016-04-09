#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    using namespace std::placeholders;
    vector<int> ivec = {3,5,7,2,4,9};
    int divisor = 3;
    // calls modulus<int>().operator()(*iterator, divisor)
    // returns *iterator % divisor
    // then calls equal_to<int>().operator()(*iterator % divisor, 0)
    // returns *iterator % divisor == 0
    cout << any_of(ivec.cbegin(), ivec.cend(), bind(equal_to<int>(), bind(modulus<int>(), _1, divisor), 0)) << endl;
    return 0;
}