#include <iostream>
#include <cstddef>
#include <iterator>
using namespace std;
int main()
{
    int arr[10];
    int *b = begin(arr), *e = end(arr);
    for (int *p = b; p != e; p++)
        *p = 0;
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}