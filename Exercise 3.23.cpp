#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums(10);
    for (int i = 0; i < 10; i++)
        cin >> nums[i];
    for (auto it = nums.begin(); it != nums.end(); it++)
        *it = 2*(*it);
    for (auto it = nums.begin(); it != nums.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
