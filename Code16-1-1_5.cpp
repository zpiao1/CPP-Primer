#include "Sales_data.h"
#include <iostream>
using namespace std;
template <typename T>
int compare(const T& v1, const T& v2)
{
    if (v1 < v2) return -1; // requires < on objects of type T
    if (v2 < v1) return 1;  // requires < on objects of type T
    return 0;               // returns int; not dependent on T
}
int main()
{
    Sales_data data1, data2;
    cout << compare(data1, data2) << endl;  // error: no  < on Sales_data
    return 0;
}