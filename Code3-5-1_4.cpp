#include <iostream>
using namespace std;
int main()
{
    int a[] = {0, 1, 2};    // array of three ints
    int a2[] = a;           // error: cannot intialize one array with another
    a2 = a;                 // error: cannot assign one array to another
    return 0;
}