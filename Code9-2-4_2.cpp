#include <array>
#include <string>
using namespace std;
int main()
{
    array<int, 42>      // type is: array that holds 42 ints
    array<string, 10>   // type is: array that holds 10 strings
    array<int, 10>::size_type i;    // array type includes element type and size
    array<int>::size_type j;        // error: array<int> is not a type
    array<int, 10> ia1; // ten default-initialized ints
    array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9}; // list initialization
    array<int, 10> ia3 = {42};  // ia3[0] = 42, remaining elements are 0
    int digs[10] = {0,1,2,3,4,5,6,7,8,9};
    int cpy[10] = digs; // error: no copy or assignment for built-in arrays
    array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> copy = digits;   // ok: so long as array types match
    return 0;
}