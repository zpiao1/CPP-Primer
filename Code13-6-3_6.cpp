#include <vector>
#include <algorithm>
using namespace std;
class Foo {
public:
    Foo sorted() &&;        // may run on modifiable rvalues
    Foo sorted() const &;   // may run on any kind of Foo
    // other members of Foo
private:
    vector<int> data;
};
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}
// this object is either const or it is lvalue; either way we can't sort in place
Foo Foo::sorted() const &
{
    Foo ret(*this);                         // make a copy
    sort(ret.data.begin(), ret.data.end()); // sort the copy
    return ret;                             // return the copy
}
Foo retVal();
Foo &retFoo();
int main()
{
    retVal().sorted();  // retVal() is an rvalue, calls Foo::sorted() &&
    retFoo().sorted();  // retFoo() is an lvalue, calls Foo::sorted() const &
    return 0;
}