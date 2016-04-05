#include <iostream>
using namespace std;
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
f(5.6);     // calls void f(double, double)