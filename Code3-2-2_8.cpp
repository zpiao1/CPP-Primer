#include <iostream>
#include <string>
using namespace std;
int main()
{
    string st1(10, 'c'), st2;   // st1 is cccccccccc; st2 is an empty string
    st1 = st2;  // assignment: replace contents of st1 with a copy of st2
                // both st1 and st2 are now the empty string
    return 0;
}



