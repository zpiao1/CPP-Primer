#include <vector>
#include <iostream>
using namespace std;
using const_it = vector<int>::const_iterator;
const_it find(const_it cbegin, const_it cend, int val);
int main()
{
    vector<int> vec;
    const_it iter;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);
    iter = find(vec.cbegin(), vec.cend(), 5);
    if (iter != vec.cend())
        cout << *iter << endl;
    else
        cout << "5 is not found" << endl;
    iter = find(vec.cbegin(), vec.cend(), 13);
    if (iter != vec.cend())
        cout << *iter << endl;
    else
        cout << "13 is not found" << endl;
    return 0;
}
const_it find(const_it cbegin, const_it cend, int val)
{
    while (cbegin != cend) {
        if (*cbegin == val)
            return cbegin;
        cbegin++;
    }
    return cend;
}