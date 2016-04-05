#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    list<int> ilist = {0,3,5,0,6,0,0,3};
    auto iter = find(ilist.crbegin(), ilist.crend(), 0);
    cout << *iter << endl;
    return 0;
}