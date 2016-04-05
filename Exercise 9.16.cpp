#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
    vector<int> v = {1,2,3,4};
    list<int> l = {1,2,3,5};
    if (v.size() != l.size())
        cout << "v != l" << endl;
    else {
        auto vit = v.cbegin();
        auto lit = l.cbegin();
        while (vit != v.cend() && lit != l.cend()) {
            if (*vit != *lit) {
                cout << "v != l" << endl;
                return 0;
            }
            vit++;
            lit++;
        }
        cout << "v == l" << endl;
    }
    return 0;
}