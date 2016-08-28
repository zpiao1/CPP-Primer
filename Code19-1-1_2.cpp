#include <new>
#include <cstdlib>
using namespace std;
// these versions might throw an exception
void *operator new(size_t); // allocate an object
void *operator new[](size_t);   // allocate an array
void *operator delete(void*) noexcept;  // free an object
void *operator delete[](void*) noexcept;    // free an array
// versions that promise not to throw; see § 12.1.2 (p. 460)
void *operator new(size_t, nothrow_t&) noexcept;
void *operator new[](size_t, nothrow_t&) noexcept;
void *operator delete(void*, nothrow_t&) noexcept;
void *operator delete[](void*, nothrow_t&) noexcept;

void *operator new(size_t, void*);  // this version may not be redefined

void *operator new(size_t size) {
    if (void *mem = malloc(size))
        return mem;
    else
        throw bad_alloc();
}
void operator delete(void *mem) noexcept { free(mem); }