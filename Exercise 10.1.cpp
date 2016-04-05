#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int num;
    vector<int> vec;
    while (cin >> num) 
        vec.push_back(num);
    cout << "# of 1's: " << count(vec.cbegin(), vec.cend(), 1) << endl;
    return 0;
}