using namespace std;
class Base {
public:
    virtual double f1(double) noexcept; // doesn't throw
    virtual int f2() noexcep(false);    // can throw
    virtual void f3();  // can throw
};
class Derived : public Base {
public:
    double f1(double);  // error: Base::f1 promises not to throw
    int f2() noexcept(false);   // ok: same specification as Base::f2
    void f3() noexcept; // ok: Derived::f3 is more restrictive
};