#include <itertor>
#include <list>
using namespace std;
int main()
{
    list<int> lst = {1,2,3,4};
    list<int> lst2, lst3;   // empty list
    // after copy completes, lst2 contains 4 3 2 1
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    // after copy completes, lst3 contains 1 2 3 4
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    return 0;
}