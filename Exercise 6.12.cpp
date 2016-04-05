#include <iostream>
#include "Chapter6.h"
void swap_ref(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}