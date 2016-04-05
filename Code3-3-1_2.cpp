#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> ivec;       // initially empty
    // give ivec some values
    vector<int> ivec2(ivec);    // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec;   // copy elements of ivec into ivec3
    //vector<string> svec(ivec2); // error: svec holds strings, not ints

    vector<string> v1{"a", "an", "the"};    // list initialization
    //vector<string> v2("a", "an", "the");    // error
    return 0;
}
