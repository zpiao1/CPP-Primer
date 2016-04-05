#include <iostream>
#include <initializer_list>
#include "Chapter6.h"
using namespace std;
int main()
{
    cout << sum_list({1,2,3,4,5,6,7,8,9,10}) << endl;
    return 0;
}
int sum_list(initializer_list<int> il)
{
    int sum = 0;
    for (auto i : il)
        sum += i;
    return sum;
}