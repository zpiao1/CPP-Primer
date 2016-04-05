#include <iostream>
#include "Chapter6.h"
using namespace std;
int main()
{
    int a = 1, b = 2;
    cout << larger(a, &b) << endl;
    return 0;
}
int larger(int a, const int *pb)
{
    return (a > *pb ? a : *pb);
}