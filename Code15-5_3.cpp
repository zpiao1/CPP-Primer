using namespace std;
class Base {
    // added friend declaration; other members as before
    friend class Pal;   // Pal has no access to classes derived from Base
public:
    void pub_mem(); // public member
protected:
    int prot_mem;   // protected member
private:
    char priv_mem;  // private member
};
class Sneaky : public Base {
    friend void clobber(Sneaky&);   // can access Sneaky::prot_mem
    friend void clobber(Base&);     // can't access Base::prot_mem
    int j;                          // j is private by default
};
class Pal {
public:
    int f(Base b) { return b.prot_mem; }    // ok: Pal is a friend of Base
    int f2(Sneaky s) { return s.j; };       // error: Pal not friend of Sneaky
    // access to a base class is controlled by the base class, even inside a derived object
    int f3(Sneaky s) { return s.prot_mem; } // ok: Pal is a friend
};
// D2 has no access to protected or private members in Base
class D2 : public Pal {
public:
    int mem(Base b) {
        return b.prot_mem;  // error: friendship doesn't inherit
    }
};
