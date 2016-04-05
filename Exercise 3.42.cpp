#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec{3,0,2,4,7,0,0};
    int arr[7];
    for (int i = 0; i < vec.size(); i++)
        arr[i] = vec[i];
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}