#include <iostream>
using namespace std;
// despite appearances, these three declarations of print are equivalent
// each function has a single parameter of type const int*
void print(const int*);
void print(const int[]);    // shows the intent that the function takes an array
void print(const int[10]);  // dimension for documentation purposes (at best)
int main()
{
    int i = 0, j[2] = {0, 1};
    print(&i);  // ok: &i is int*
    print(j);   // ok: j is converted to an int* that points to j[0]
    return 0;
}