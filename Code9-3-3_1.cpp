#include <list>
using namespace std;
int main()
{
    while (!ilist.empty()) {
        process(ilist.front()); // do something with the current top of ilist
        ilist.pop_front();      // done; remove the first element
    }
    return 0;
}