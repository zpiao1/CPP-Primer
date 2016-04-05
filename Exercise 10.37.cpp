#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    list<int> ilist;
    auto liter = back_inserter(ilist);
    auto r_vbeg = ivec.crbegin();
    auto r_vend = ivec.crbegin();
    while (r_vbeg != ivec.crend() && *r_vbeg != ivec[7])
        ++r_vbeg;
    while (r_vend != ivec.crend() && *r_vend != ivec[3])
        ++r_vend;
    ++r_vend;
    copy(r_vbeg, r_vend, liter);
    for (auto i : ilist)
        cout << i << ' ';
    cout << endl;
}