#include <iostream>
#include <cstddef>
using namespace std;
int main()
{
    int arr[10];
    for (size_t index = 0; index < 10; index++)
        arr[index] = index;
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}