#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string str;
    list<string> lst;
    while (cin >> str) 
        lst.push_back(str);
    cout << "# of \"hello\"s: " << count(lst.cbegin(), lst.cend(), "hello") << endl;
    return 0;
}