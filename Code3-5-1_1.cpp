#include <iostream>
#include <string>
using namespace std;
int main()
{
    unsigned cnt = 42;          // not a constant expression
    constexpr unsigned sz = 42; // constant expression
                                // constexpr see § 2.4.4 (p. 66)
    int arr[10];                // array of ten ints
    int *parr[sz];              // array of 42 pointers to int
    string bad[cnt];            // error: cnt is not a constant expression
    string strs[get_size()];    // ok if get_size is constexpr, error other wise
    return 0;
}