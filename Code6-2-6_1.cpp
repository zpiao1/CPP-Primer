#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;
int main()
{
    initializer_list<string> ls;    // initializer_list of strings
    initializer_list<int> li;       // initializer_list of ints
    // expected, actual are strings
    if (expected != actual)
        error_msg({"functionX", expected, actual});
    else
        error_msg({"functionX", "okay"});
    return 0;
}
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg) 
        cout << *beg << " ";
    cout << endl;
}