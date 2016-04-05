#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    for (auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter)
        cout << *r_iter << endl;
    return 0;
}