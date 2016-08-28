#include <typeinfo>
using namespace std;
class Base {
    friend bool operator=(const Base&, const Base&);
public:
    // interface members for Base
protected:
    virtual bool equal(const Base&) const;
    // data and other implementation members of Base
};
class Derived: public Base {
public:
    // other interface members for Derived
protected:
    bool equal(const Base&) const;
    // data and other implementation members of Derived
};

bool operator==(const Base& lhs, const Base& rhs)
{
    // returns false if typeids are different; otherwise make a virtual call to equal
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Derived::equal(const Base &rhs) const
{
    // we know the types are equal, so the cast won't throw
    auto r = dynamic_cast<const Derived&>(rhs);
    // do the work to compare two Derived objects and return the result
}

bool Base::equal(const Base &rhs) const
{
    // do whatever is required to compare to Base objects
}