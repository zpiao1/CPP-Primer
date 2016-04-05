#include <iostream>
#include <vector>
#include "Chapter6.h"
using namespace std;
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
vector<int(*)(int, int)> vf{&add, &subtract, &multiply, &divide};
int main()
{
    for (auto ele : vf) {
        cout << (*ele)(6, 3) << endl;
    }
    return 0;
}
int add(int a, int b)
{
    return a+b;
}
int subtract(int a, int b)
{
    return a-b;
}
int multiply(int a, int b)
{
    return a*b;
}
int divide(int a, int b)
{
    return a/b;
}

