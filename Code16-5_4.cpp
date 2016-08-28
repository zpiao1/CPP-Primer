#include <string>
using namespace std;
template <typename T> struct Foo {
    Foo(const T &t = T()): mem(t) {}
    void Bar() { /* ... */ }
    T mem;
    // other members of Foo
};
template <> // we're specializing a template
void Foo<int>::Bar()    // we're specializing the Bar member of Foo<int>
{
    // do whatever specialized processing that applies to ints
}
int main()
{
    Foo<string> fs; // instantiates Foo<string>::Foo()
    fs.Bar();   // instantiates Foo<string>::Bar()
    Foo<int> fi;    // instantiates Foo<int>::Foo()
    fi.Bar();   // uses our specialization of Foo<int>::Bar()
    return 0;
}