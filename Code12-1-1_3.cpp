#include <memory>
using namespace std;
// factory returns a shared_ptr pointing to a dynamically allocated object
shared_ptr<Foo> factory(T arg)
{
    // process arg as appropriate
    return make_shared<Foo>(arg);
}
void use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);
    // use p
}   // p goes out of scope; the memory to which p points is automatically freed
shared_ptr<Foo> use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);
    // use p
    return p;   // reference count is incremented when we return p
}   // p goes out of scope; the memory to which p points is not freed