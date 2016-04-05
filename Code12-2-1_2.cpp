#include <string>
using namespace std;
int main()
{
    int *pia = new int[10]; // block of ten uninitialized ints
    int *pia2 = new int[10]();  // block of ten ints value initialized to 0
    string *psa = new string[10];   // block of ten empty strings
    string *psa2 = new string[10]();    // block os ten empty strings
    // block of ten ints each initialized from the corresponding initializer
    int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    // block of ten strings; the first four are initialized from the given initializers
    // remaining elements are value initialized
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};
    return 0;
}