#include <vector>
using namespace std;
int main()
{
    // disaster: the behavior of this loop is undefined
    auto begin = v.begin(),
         end = v.end();     // bad idea, saving the value of the end iterator
    while (begin != end) {
        // do some processing
        // insert the new value and reassign begin, which otherwise would be invalid
        ++begin;    // advance begin because we want to insert after this element
        begin = v.insert(begin, 42);    // insert the new value
        ++begin;    // advance begin past the element we just added
    }
    return 0;
}