#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    // pbeg points to the first and pend points just past the last element in arr
    int *pbeg = begin(arr), *pend = end(arr);
    // find the first negative element, stopping if we've seen all the elements
    while (pbeg != pend && *pbeg >= 0)
        ++pbeg;
    return 0;
}