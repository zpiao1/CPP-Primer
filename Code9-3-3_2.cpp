#include <list>
using namespace std;
int main()
{
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.begin();
    while (it != lst.end())
        if (*it % 2)            // if the element is odd
            it = lst.erase(it); // erase the element
        else
            ++it;
    return 0;
}
