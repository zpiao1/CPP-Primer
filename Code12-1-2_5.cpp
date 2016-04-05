#include <new>
using namespace std;
int main()
{
    // if allocation fails, new returns a null pointer
    int *p1 = new int;  // if allocation fails, new throws std::bad_alloc
    int *p2 = new (nothrow) int;    // if allocation fails, new returns a null pointer
    return 0;
}