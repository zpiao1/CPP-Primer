#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> emptyVec;
    if (!emptyVec.empty()) {
        auto i1 = emptyVec.at(0);
        cout << i1 << endl;
        auto i2 = emptyVec[0];
        cout << i2 << endl;
        auto it = emptyVec.begin();
        cout << *it << endl;
        auto i3 = emptyVec.front();
        cout << i3 << endl;
    }
    try {
        auto i = emptyVec.at(0);
        cout << i << endl;
    } catch (out_of_range err) {
        cout << err.what();
    }
    return 0;
}