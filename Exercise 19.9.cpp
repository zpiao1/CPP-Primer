#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>
using namespace std;
void f();
int main()
{
    int a[4];
    int *p;
    cout << typeid(int).name() << endl
         << typeid(double).name() << endl
         << typeid(long).name() << endl
         << typeid(char).name() << endl
         << typeid(long long).name() << endl
         << typeid(float).name() << endl
         << typeid(string).name() << endl
         << typeid(vector<int>).name() << endl
         << typeid(list<int>).name() << endl
         << typeid(set<int>).name() << endl
         << typeid(map<int, int>).name() << endl
         << typeid(unordered_map<int, int>).name() << endl
         << typeid(unordered_set<int>).name() << endl
         << typeid(a).name() << endl
         << typeid(p).name() << endl
         << typeid(decltype(f)).name() << endl;
    return 0;
}