#include <memory>
using namespace std;
// Possible statement in the shared_ptr<T> destructor
// value of del known only at run time; call through a pointer
del ? del(p) : delete p;    // del(p) requires run-time jump to del's location
// Possible statement in the unique_ptr destructor
// del bound at compile time; direct call to the deleter is instantiated
del(p); // no run-time overhead