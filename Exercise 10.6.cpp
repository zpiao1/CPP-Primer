#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> vec;
    fill_n(back_inserter(vec), 10, 0);
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
    return 0;
}