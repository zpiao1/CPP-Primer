using namespace std;
class Base { /* ... */ };
class D: public Base {
public:
    // by default, the base class default constructor initializes the base part of an object
    // to use the copy or move constructor, we must explicitly call that
    // constructor in the constructon initializer list
    D(const D& d): Base(d)  // copy the base members
        /* initializers for members of D */ { /* ... */ }
    D(D&& d): Base(std::move(d))    // move the base members
        /* initializers for members of D */ { /* ... */ }
    D &operator=(const D &rhs);
    // Base::~Base invoked automatically
    ~D() { /* do what it takes to clean up derived members */ }
};
// Base::operator=(const Base &rhs) is not invoked automatically
D &D::operator=(const D &rhs)
{
    Base::operator=(rhs);   // assigns the base part
    // assign members in the derived class, as usual,
    // handling self-assignment and freeing existing resources as appropriate
    return *this;
}