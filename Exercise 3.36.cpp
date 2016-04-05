#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int arr1[5] = {0,2,5,6,8};
    int arr2[5] = {0,2,5,6,7};
    vector<int> v1{0,2,5,6,8};
    vector<int> v2{0,2,5,6,7};
    size_t i;
    for (i = 0; i < 5; i++)
        if (arr1[i] > arr2[i]) {
            cout << "arr1 > arr2" << endl;
            break;
        }
        else if (arr1[i] < arr2[i]) {
            cout << "arr1 < arr2" << endl;
            break;
        }
    if (i == 5)
        cout << "arr1 == arr2" << endl;
    if (v1 < v2)
        cout << "v1 < v2" << endl;
    else if (v1 == v2)
        cout << "v1 == v2" << endl;
    else
        cout << "v1 > v2" << endl;
    return 0;
}