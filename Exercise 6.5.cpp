#include <iostream>
#include "Chapter6.h"
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    cout << "abs(" << num << ") = " << abs_val(num) << endl;
    return 0;
}

int abs_val(int num)
{
    return (num > 0 ? num : -num);
}