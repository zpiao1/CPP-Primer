using namespace std;
class Base {
public:
    static void statmem();
};
class Derived : public Base {
    void f(const Derived &);
};
void Derived::f(const Derived &derived_obj)
{
    Base::statmem();        // ok: Base defines statmem
    Derived::statmem();     // ok: Derived inherits statmem
    // ok: derived objects can be used to access static from base
    derived_obj.statmem();  // accessed through a Derived object
    statmem();              // accessed through this object
}
