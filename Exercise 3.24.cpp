#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums;
    int value;
    while (cin >> value)
        nums.push_back(value);
    auto beg = nums.begin(), end = nums.end();
    for (auto it = beg; it != end && it + 1 != end; ++it)
        cout << *it + *(it + 1) << " ";
    cout << endl;
    for (auto it = beg; it <= beg + (end - it); ++it)
        cout << *it + *(beg + (end - it - 1)) << " ";
    cout << endl;
    return 0;
}