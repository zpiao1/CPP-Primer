#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> strs;
    string aStr;
    while (cin >> aStr)
        strs.push_back(aStr);
    for (auto val : strs)
        cout << val << endl;
    return 0;
}
