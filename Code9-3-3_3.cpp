#include <list>
#include <string>
using namespace std;
int main()
{
    // delete the range of elements between two iterators
    // returns an iterator to the element just after the last removed element
    elem1 = slist.erase(elem1, elem2);  // after the call elem1 == elem2
    slist.clear();      // delete all the elements with in the container
    slist.erase(slist.begin(), slist.end());    // equivalent
    return 0;
}
