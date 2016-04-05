#include <string>
#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<string> lst;
    auto iter = lst.begin();
    while (cin >> word)
        iter = lst.insert(iter, word);  // same as calling push_front
    return 0;
}