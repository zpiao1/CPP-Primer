#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};   // ia is an array of ten ints
    int *beg = begin(ia);               // pointer to the first element in ia
    int *last = end(ia);                // pointer one past the last element in ia
    return 0;
}