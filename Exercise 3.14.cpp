#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> ints;
    int num;
    while (cin >> num)
        ints.push_back(num);
    for (auto val : ints)
        cout << val << " ";
    cout << endl;
    return 0;
}
