#include <iostream>
#include "Chapter6.h"
using namespace std;
int fact_interact(int num)
{
    int fact = 1;
    while (num > 1)
        fact *= num--;
    return fact;
}