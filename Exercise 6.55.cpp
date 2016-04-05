#include <iostream>
#include <vector>
#include "Chapter6.h"
using namespace std;
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
vector<int(*)(int, int)> vf{&add, &subtract, &multiply, &divide};