#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int val = 42;   // value we'll look for
    // result will denote the element we want if it's in vec, or vec.cend() if not
    auto result = find(vec.cbegin(), vec.cend(), val); 
    // report the result
    cout << "The value " << val << (result == vec.cend() ? " is not present" : " is present") << endl;
    return 0;
}