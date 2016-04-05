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
        for (auto it1 = v1.cbegin(); it1 != v1.cend(); it1++)
            cout << *it1 << " ";
    else
        cout << "v1 is empty";
    cout << endl;

    cout << v2.size() << endl;
    if (v2.size() != 0)
        for (auto it2 = v2.cbegin(); it2 != v2.cend(); it2++)
            cout << *it2 << " ";
    else
        cout << "v2 is empty";
    cout << endl;

    cout << v3.size() << endl;
    if (v3.size() != 0)
        for (auto it3 = v3.cbegin(); it3 != v3.cend(); it3++)
            cout << *it3 << " ";
    else
        cout << "v3 is empty";
    cout << endl;

    cout << v4.size() << endl;
    if (v4.size() != 0)
        for (auto it4 = v4.cbegin(); it4 != v4.cend(); it4++)
            cout << *it4 << " ";
    else
        cout << "v4 is empty";
    cout << endl;

    cout << v5.size() << endl;
    if (v5.size() != 0)
        for (auto it5 = v5.cbegin(); it5 != v5.cend(); it5++)
            cout << *it5 << " ";
    else
        cout << "v5 is empty";
    cout << endl;

    cout << v6.size() << endl;
    if (v6.size() != 0)
        for (auto it6 = v6.cbegin(); it6 != v6.cend(); it6++)
            cout << *it6 << " ";
    else
        cout << "v6 is empty";
    cout << endl;

    cout << v7.size() << endl;
    if (v7.size() != 0)
        for (auto it7 = v7.cbegin(); it7 != v7.cend(); it7++)
            cout << *it7 << " ";
    else
        cout << "v7 is empty";
    cout << endl;

    return 0;
}

