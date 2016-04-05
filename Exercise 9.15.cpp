#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {2,4,6,8};
    cout << (v1 == v2) << endl;
    return 0;
}