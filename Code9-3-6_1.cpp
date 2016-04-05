#include <vector>
using namespace std;
int main()
{
    // silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);  // duplicate the current element
            iter += 2;      // advance past this element and the one inserted before it
        } else
            iter = vi.erase(iter);          // remove even elements
            // don't advance the iterator; iter denotes the element after the one we erased
    }
    return 0;
}