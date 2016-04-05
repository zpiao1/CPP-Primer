#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    // replace any element with the value 0 with 42
    replace(ilst.begin(), ilst.end(), 0, 42);
    // use back_inserter to grow destination as needed
    replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(ivec), 0, 42);
    return 0;
}