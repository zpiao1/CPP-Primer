#include <memory>
void f()
{
    shared_ptr<int> sp(new int(42));    // allocate a new object
    // code that throws an exception that is not caught inside f
}   // shard_ptr freed automatically when the function ends
void f()
{
    int *ip = new int(42);  // dynamically allocate a new object
    // code that throws an exception that is not caught inside f
    delete ip;              // free the memory before exiting
}