#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums;
    int value;
    while (cin >> value)
        nums.push_back(value);
    for (decltype(nums.size()) index = 0; index < nums.size() - 1;
         ++index)
        cout << nums[index] + nums[index+1] << " ";
    cout << endl;

    for (decltype(nums.size()) index = 0; 2*index < nums.size(); ++index)
        cout << nums[index] + nums[nums.size()-index-1] << " ";
    cout << endl;
    return 0;
}
