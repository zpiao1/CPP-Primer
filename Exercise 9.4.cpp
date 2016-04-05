#include <vector>
#include <iostream>
using namespace std;
using const_it = vector<int>::const_iterator;
bool isFound(const_it cbegin, const_it cend, int val);
int main()
{
    vector<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);
    cout << isFound(vec.cbegin(), vec.cend(), 5) << endl;
    cout << isFound(vec.cbegin(), vec.cend(), 12) << endl;
    return 0;
}
bool isFound(const_it cbegin, const_it cend, int val)
{
    while (cbegin != cend) {
        if (*cbegin == val)
            return true;
        cbegin++;
    }
    return false;
}