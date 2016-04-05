#define NDEBUG
#include <iostream>
#include <vector>
#include <cassert>
#include "Chapter6.h"
using namespace std;
int main()
{
    vector<int> vec{1,2,3,4,5};
    printVec(vec, vec.begin());
    return 0;
}
void printVec(const vector<int> &vec, const vector<int>::iterator &it)
{
    if (it != vec.end()) {
        cout << *it << endl;
        printVec(vec, it + 1);
        assert(vec.size() == 4);
    }
}