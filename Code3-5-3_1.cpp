#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nums[] = {"one", "two", "three"};    // array of strings
    string *p = &nums[0];       // p points to the first element in nums
    string *p2 = nums;          // equivalent to p2 = &nums[0]
    int ia[] = {0,1,2,3,4,5,6,7,8,9};   // ia is an array of ten ints
    auto ia2(ia);       // ia2 is an int* that points to the first element in ia
    ia2 = 42;           // error: ia2 is a pointer, and we can't assign an int to a pointer
    // auto ia2(&ia[0]);    // now it's clear that ia2 has type int*
    // ia2 is an array of ten ints
    decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};
    ia3 = p;            // error: can't assign an int* to an array
    ia3[4] = i;         // ok: assigns the value of i to an element in ia3
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int *p = arr;       // p points to the first element in ar
    ++p;                // p points to arr[1]
    int *e = &arr[10];  // pointer just past the last element in arr
    for (int *b = arr; b != e; ++b)
        cout << *b << endl;     // print the elements in arr
    return 0;
}