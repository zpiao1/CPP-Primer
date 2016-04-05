#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {3,0,2,4,7,0,0};
    vector<int> vec(begin(arr), end(arr));
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}