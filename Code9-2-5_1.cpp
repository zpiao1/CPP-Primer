#include <array>
using namespace std; 
int main()
{
    array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> a2 = {0};    // elements all have value 0
    a1 = a2;    // replaces elements in a1
    a2 = {0};   // error: cannot assign to an array from a braced list
    return 0;
}