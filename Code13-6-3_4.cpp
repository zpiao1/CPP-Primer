using namespace std;
class Foo {
public:
    Foo &operator=(const Foo&) &;   // may assign only to modifiable lvalues
    // other members of Foo;
};
Foo &Foo::operator=(const Foo &rhs) &
{
    // do whatever is needd to assign rhs to this object
    return *this;
}
Foo &retFoo();  // returns a reference; a call to retFoo is an lvalue
Foo retVal();   // returns by value; a call to retVal is an rvalue
int main()
{
    Foo i,j;    // i and j are lvalues;
    i = j;      // ok: i is an lvalue
    retFoo() = j;   // ok: retFoo() returns an lvalue;
    retVal() = j;   // error: retVal() returns an rvalue
    i = retVal();   // ok: we can pass an rvalue as the right-hand operand to assignment
    return 0;
}