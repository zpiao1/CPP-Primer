using namespace std;
struct A {
    A(int = 0); // usually a bad idea to have two
    A(double);  // conversions from arithmetic types
    operator int() const;   // usually a bad idea to have two
    operator double() const;    // conversions to arithmetic types
    // other members
};
void f2(long double);
int main()
{
    A a;
    f2(a);  // error ambiguous: f(A::operator int())
            //               or f(A::operator double())
    long lg;
    A a2(lg);   // error ambiguous: A::A(int) or A::A(double)
    short s = 42;
    // promoting short to int is better than converting short to double
    A a3(s);    // uses A::A(int)
    return 0;
}