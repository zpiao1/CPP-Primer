#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
    unique(beg, end);               // uses the == operator
    unique(beg, end, comp);         // uses comp to compare the elements
    find(beg, end, val);            // find the first instance of val in the input range
    find_if(beg, end, pred);        // find the first instance for which pred is true
    reverse(beg, end);              // reverse the elements in the input range
    reverse_copy(beg, end, dest);   // copyt the elements in reverse order into dest
    // removes the odd elements from v1
    remove_if(v1.begin(), v1.end(), [](int i) {
        return i % 2;
    });
    // copies only the even elements from v1 into v2; vi is unchanged
    remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int i) {
        return i % 2;
    });
    return 0;
}