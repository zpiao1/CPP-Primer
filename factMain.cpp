#include <iostream>
#include "Chapter6.h"
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    cout << num << "! = " << fact_interact(num) << endl;
    return 0;
}