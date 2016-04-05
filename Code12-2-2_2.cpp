#include <memory>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    allocator<string> alloc;    // object that can allocate strings
    auto const p = alloc.allocate(n);   // allocate n unconstructed strings
    auto q = p; // q will point to one past the last constructed element
    alloc.construct(q++);   // *q is the empty string
    alloc.construct(q++, 10, 'c');  // *q is cccccccccc
    alloc.construct(q++, "hi"); // *q is hi!
    cout << *p << endl; // ok: uses the string output operator
    cout << *q << endl; // disaster: q points to unconstructed memory!
    while (q != p)
        alloc.destroy(--q); // free the strings we actually allocated
    alloc.deallocate(p, n);
    return 0;
}