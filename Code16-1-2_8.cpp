#include <string>
template <typename T> class Foo {
public:
    static std::size_t count() { return ctr; }
    // other interface members
private:
    static std::size_t ctr;
    // other implementation members
};
using namespace std;
template <typename T>
size_t Foo<T>::ctr = 0; // define and initialize ctr
int main()
{
    // instantiates static members Foo<string>::ctr and Foo<string>::count
    Foo<string> fs;
    // all three objects share the same Foo<int>::ctr and Foo<int>::count members
    Foo<int> fi, fi2, fi3;  // instantiates Foo<int> class
                            // and the static data member ctr
    auto ct = Foo<int>::count();    // instantiates Foo<int>::count
    ct = fi.count();    // uses Foo<int>::count
    ct = Foo::count();  // error: which template instantiation?
    return 0;
}