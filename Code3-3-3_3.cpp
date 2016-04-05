#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> ivec;       // empty vector
    // for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    //     ivec[ix] = ix;   // disaster: ivec has no elements
    for (decltype(ivec.size()) ix = 0; ix != 0; ++ix)
        ivec.push_back(ix); // ok: adds a new elements with value ix
    return 0;
}
