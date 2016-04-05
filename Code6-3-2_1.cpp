#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    if (some_failure)
        return EXIT_FAILURE;    // defined in cstdlib
    else 
        return EXIT_SUCCESS;    // defined in cstdlib
}