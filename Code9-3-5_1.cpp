#include <list>
using namespace std;
int main()
{
    list<int> ilist(10, 42);    // ten ints: each has value 42
    ilist.resize(15);           // adds five elements of value 0 to the back of ilist
    ilist.resize(25, -1);       // adds ten elements of value -1 to tha beck of ilist
    ilist.resize(5);            // erases 20 elements from the back of ilist
    return 0;
}
