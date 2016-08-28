#include <vector>
#include <string>
#include "Blob.h"
#include <type_traits>
using namespace std;
template <typename T>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // process the range
    return *beg;    // return a reference to an element from the range
}
template <typename T>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{
    // process the range
    return *beg;    // return a copy of an element from the range
}
int main()
{
    vector<int> vi = {1,2,3,4,5};
    Blob<string> ca = { "hi", "bye" };
    auto &i = fcn(vi.begin(), vi.end());    // fcn should return int&
    auto &s = fcn(ca.begin(), ca.end());    // fcn should return string&
    return 0;
}