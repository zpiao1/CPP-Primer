#include <iostream>
using namespace std;
int fact(int val);
int main()
{
    int j = fact(5);    // j equals 120, i.e. the result of fact(5)
    cout << "5! is " << j << endl;
    return 0;
}
// factorial of val is val * (val - 1) * (val - 2) ... * ((val - (val - 1)) * 1)
int fact(int val)
{
    int ret = 1;    // local variable to hold the result as we calculate it
    while (val > 1)
        ret *= val--;   // assign ret * val to ret and decrement val
    return ret;         // return the result
}
