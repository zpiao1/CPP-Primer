using namespace std;
// factory returns a pointer to a dynamically allocated object
Foo *factory(T arg)
{
    // process arg as appropriate
    return new Foo(arg);    // caller is responsible for deleting this memory
}
void use_factory(T arg)
{
    Foo *p = factory(arg);
    // use p but do not delete it
}   // p goes out of scope, but the memory to which p points is not freed!
void use_factory(T arg)
{
    Foo *p = factory(arg);
    // use p
    delete p;   // remember to free the memory now that we no longer need it
}
Foo *use_factory(T arg)
{
    Foo *p = factory(arg);
    // use p
    return p;   // caller must delete the memory
}