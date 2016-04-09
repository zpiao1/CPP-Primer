using namespace std;
// usually a bad idea to have mutual conversions between two class types
struct B;
struct A {
    A() = default;
    A(const B&);    // converts a B to an A
    // other members
};
struct B {
    operator A() const; // also converts a B to an A
    // other members
};
A f(const A&);
int main()
{
    B b;
    A a = f(b); // error ambiguous: f(B::operator A())
                //               or f(A::A(const B&))
    A a1 = f(b.operator A());   // ok: use B's conversion operator
    A a2 = f(A(b));             // ok: use A's constructor
    return 0;
}
