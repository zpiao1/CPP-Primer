#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;
int main()
{
    int arr[10];
    int arr2[10];
    vector<int> vec;
    vector<int> vec2;
    for (size_t index = 0; index < 10; index++)
        arr[index] = index;
    for (size_t index = 0; index < 10; index++)
        arr2[index] = arr[index];
    for (size_t index = 0; index < 10; index++)
        vec.push_back(index);
    vec2 = vec;
    for (auto i : arr2)
        cout << i << " ";
    cout << endl;
    for (auto i : vec2)
        cout << i << " ";
    cout << endl;
    return 0;
}