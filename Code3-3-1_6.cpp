#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1(10);     // v1 has ten elements with value 0
    vector<int> v2{10};     // v2 has one element with value 10
    vector<int> v3(10, 1);  // v3 has ten elements with value 1
    vector<int> v4{10, 1};  // v4 has two elements with values 10 and 1
    vector<string> v5{"hi"};    // list initialization: v5 has one element
    vector<string> v6("hi");    // error: can't construct a vector from a string literal
    vector<string> v7{10};      // v7 has ten default-initialized elements;
    vector<string> v8{10, "hi"};    // v8 has ten elements with value "hi"
    return 0;
}
