#include <iostream>
using namespace std;
void reset(int *ip);
int main()
{
    int i = 42;
    reset(&i);                      // changes i but not the address of i
    cout << "i = " << i << endl;    // prints i = 0
    return 0;
}
// function that takes a pointer and sets the pointed-to value to zero
void reset(int *ip)
{
    *ip = 0;    // changes the value of the object to which ip points
    ip = 0;     // changes only the local copy of ip; the argument is unchanged
}