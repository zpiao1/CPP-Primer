#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : vec)
        *out_iter++ = e;    // the assignment writes this element to cout
    cout << endl;
    for (auto e : vec)
        out_iter = e;       // the assignment writes this element to cout
    cout << endl;
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
    return 0;
}