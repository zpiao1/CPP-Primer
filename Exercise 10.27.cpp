#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v = {1,3,3,6,7,2,4,2,8};
    list<int> l;
    sort(v.begin(), v.end());
    unique_copy(v.begin(), v.end(), back_inserter(l));
    for (auto i : l)
        cout << i << ' ';
    cout << endl;
    return 0;
}