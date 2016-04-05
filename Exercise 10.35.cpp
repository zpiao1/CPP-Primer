#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    for (auto iter = ivec.cend() - 1; iter != ivec.cbegin() - 1; --iter)
        cout << *iter << endl;
    return 0;
}