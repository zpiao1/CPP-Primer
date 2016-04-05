#include <memory>
using namespace std;
// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr)
{
    // use ptr
}   // ptr goes out of scope and is destroyed
int main()
{
    shared_ptr<int> p(new int(42)); // reference count it 1
    process(p); // copying p increments its count; in process the reference count is 2
    int i = *p; // ok reference count is 1
    int *x(new int(1024));  // dangerous: x is a plain pointer, not a smart pointer
    process(x); // error: cannot convert int* to shared_ptr<int>
    process(shared_ptr<int>(x));    // legal, but the memory will be deleted!
    int j = *x; // undefined: x is a dangling pointer!
    return 0;
}