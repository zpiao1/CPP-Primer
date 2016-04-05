#include <list>
using namespace std;
int main()
{
    list<int> ilist;
    // add elements to the start of ilist
    for (size_t ix = 0; ix != 4; ++ix)
        ilist.push_front(ix);
    return 0;
}