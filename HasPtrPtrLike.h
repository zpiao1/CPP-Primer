#ifndef _HAS_PTR_PTR_LIKE_H
#define _HAS_PTR_PTR_LIKE_H
#include <string>
class HasPtr {
public:
    // constructor allocates a new string and a new counter, which it sets to 1
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // copy constructor copies all three data members and increments the counter
    HasPtr(const HasPtr &p):
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr &);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;   // member to keep track of how many objects shared *ps
};
HasPtr ~HasPtr()
{
    if (--*use == 0) {  // if the reference count goes to 0
        delete ps;  // delete the string
        delete use; // and the counter
    }
}
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // increment the use count of the right-hand operand
    if (--*use == 0) {  // then decrement this object's counter
        delete ps;      // if no other users
        delete use;     // free this object's allocated members
    }
    ps = rhs.ps;        // copy data from rhs into this object
    i = rhs.i;
    use = rhs.use;
    return *this;       // return this object
}
#endif