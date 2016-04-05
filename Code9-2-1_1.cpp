#include <iterator>
using namespace std;
int main()
{
    while (begin != end) {
        *begin = val;       // ok: range isn't empty so begin denotes an element
        ++begin;            // advance the iterator to get the next element
    }
}