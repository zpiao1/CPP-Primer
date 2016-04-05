#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    string s("Hello World");        // s holds Hello World
    char *str = s;                  // error: can't initialize a char* from a string
    const char *str = s.c_str();    // ok
    int int_arr[] = {0,1,2,3,4,5};
    // ivec has six elements; each is a copy of the corresponding element in int_arr
    vector<int> ivec(begin(int_arr), end(int_arr));
    // copies three elements: int_arr[1], int_arr[2], int_arr[3]
    vector<int> subVec(int_arr + 1, int_arr + 4);
    return 0;
}