#include <iostream>
#include <string>
using namespace std;
int main()
{
    const unsigned sz = 3;
    int ia1[sz] = {0,1,2};          // array of three ints with values 0, 1, 2
    int a2[] = {0, 1, 2};           // an array of dimension 3
    int a3[5] = {0, 1, 2};          // equivalent to a3[] = {0, 1, 2, 0, 0}
    string a4[3] = {"hi", "bye"};   // same as a4[] = {"hi", "bye", ""}
    int a5[2] = {0, 1, 2};          // error: too many initializers
    return 0;
}