using namespace std;
struct C {
    C(int);
    // other members
};
struct D {
    D(int);
    // other members
};
struct E {
    E(double);
    // other members
};
void manip(const C&);
void manip(const D&);
void manip2(const C&);
void manip2(const E&);
int main()
{
    manip(10);  // error ambiguous: manip(C(10)) or manip(D(10))
    // error ambiguous: two different user-defined conversions could be used
    manip2(10); // manip2(C(10)) or manip2(E(double(10)))
    return 0;
}