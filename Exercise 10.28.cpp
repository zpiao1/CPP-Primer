#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    list<int> list1, list2, list3;
    copy(v.begin(), v.end(), inserter(list1, list1.begin()));
    copy(v.begin(), v.end(), back_inserter(list1));
    copy(v.begin(), v.end(), front_inserter(list2));
    for (auto i : list1)
        cout << i << ' ';
    cout << endl;
    for (auto i : list2)
        cout << i << ' ';
    cout << endl;
    for (auto i : list3)
        cout << i << ' ';
    cout << endl;
    return 0;
}