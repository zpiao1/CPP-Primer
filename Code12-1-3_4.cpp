#include <memory>
int main()
{
    shared_ptr<int> p(new int(42)); // reference count is 1
    int *q = p.get();   // ok: but don't use q in any way that might delete its pointer
    {   // new block
        // undefined: two independent shared_ptrs point to the same memory
        shared_ptr<int>(q);
    }   // block ends, q is destroyed, and the memory to which q points is freed
    int foo = *p;   // undefined; the memory to which p points was freed
    p = new int(1024);  // error: cannot assign a pointer to a shared_ptr
    p.reset(new int(1024)); // ok: p points to a new object
    if (!p.unique())
        p.reset(new string(*p));    // we aren't alone; allocate a new copy
    *p += newVal;   // now that we know we're the only pointer, okay to change its object
    return 0;
}