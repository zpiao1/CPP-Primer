#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << v1.size() << endl;
    if (v1.size() != 0)
        for (auto i : v1)
            cout << i << " ";
    else
        cout << "v1 is empty";
    cout << endl;

    cout << v2.size() << endl;
    if (v2.size() != 0)
        for (auto i : v2)
            cout << i << " ";
    else
        cout << "v2 is empty";
    cout << endl;

    cout << v3.size() << endl;
    if (v3.size() != 0)
        for (auto i : v3)
            cout << i << " ";
    else
        cout << "v3 is empty";
    cout << endl;

    cout << v4.size() << endl;
    if (v4.size() != 0)
        for (auto i : v4)
            cout << i << " ";
    else
        cout << "v4 is empty";
    cout << endl;

    cout << v5.size() << endl;
    if (v5.size() != 0)
        for (auto i : v5)
            cout << i << " ";
    else
        cout << "v5 is empty";
    cout << endl;

    cout << v6.size() << endl;
    if (v6.size() != 0)
        for (auto i : v6)
            cout << i << " ";
    else
        cout << "v6 is empty";
    cout << endl;

    cout << v7.size() << endl;
    if (v7.size() != 0)
        for (auto i : v7)
            cout << i << " ";
    else
        cout << "v7 is empty";
    cout << endl;

    return 0;
}
