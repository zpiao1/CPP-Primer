#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a = {1,2};
    a.resize(5);
    cout << a.size() << endl << a.capacity() << endl;
    for (auto i : a)
        cout << i << ' ';
    cout << endl;
    a.resize(1);
    cout << a.size() << endl << a.capacity() << endl;
    for (auto i : a)
        cout << i << ' ';
    cout << endl;
    return 0;
}