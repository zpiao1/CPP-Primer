#include <iostream>
using namespace std;
typedef int arrT[10];   // arrT is a synonym for the type array of ten ints
using arrtT = int[10];  // equivalent declaration of arrT; see § 2.5.1 (p. 68)
arrT* func(int i);      // func returns a pointer to an array of five ints
int arr[10];            // arr is an array of ten ints
int *p1[10];            // p1 is an array of ten pointers
int (*p2)[10] = arr;    // p2 points to an array of ten ints
int (*func(int i))[10]; // func is a function with an int as parameter, and the return type
                        // is a pointer to an array of 10 ints
// fcn takes an int argument and returns a pointer to an array of ten ints
auto func(int i) -> int(*)[10];
int odd[] = {1,3,5,7,9};
int even[] = {2,4,6,8,10};
// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
{
    return (i % 2 ? &odd : &even);  // returns a pointer to the array
}