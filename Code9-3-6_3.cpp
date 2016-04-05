#include <vector>
using namespace std;
int main()
{
    // safer: recalculate and on each trip whenever the loop adds/erases elements
    while (begin != v.end()) {
        // do some processing
        ++begin;    // advance begin because we want to insert after this element
        begin = v.insert(begin, 42);    // insert the new value
        ++begin;
    }
    return 0;
}
