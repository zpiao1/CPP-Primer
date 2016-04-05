#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    // reverse iterator of vector from back to front
    for (auto r_iter = vec.crbegin();   // binds r_iter to the last element
              r_iter != vec.crend();    // crend refers 1 before 1st element
              ++r_iter)                 // decrements the iterator one element
        cout << *r_iter << endl;
    sort(vec.begin(), vec.end());   // sorts vec in "normal" order
    // sorts in reverse: puts the smallest element at the end of vec
    sort(vec.rbegin(), vec.rend());
    return 0;
}