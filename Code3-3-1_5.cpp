#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> vi = 10;    // error: must use direct initialization to supply a size
    // error: conversion from 'int' to non-scalar type 'std::vector<int>' requested
    return 0;
}
