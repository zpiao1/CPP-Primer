#include <iostream>
// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}
int main()
{
    int i = 0, j[2] = {0, 1};
    int k[10] = {0,1,2,3,4,5,6,7,8,9};
    print(&i);  // error: argument is not an array of ten ints
    print(j);   // error: argument is not an array of ten ints
    print(k);   // ok: argument is an array of ten ints
}