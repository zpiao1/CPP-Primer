#ifndef _HAS_PTR_H
#define _HAS_PTR_H
#include <string>
class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp):
        ps(new std::string(*hp.ps)), i(hp.i) {}
    //HasPtr &operator=(const HasPtr &rhs);
    HasPtr &operator=(HasPtr rhs);
    ~HasPtr() { delete ps; }
    // added move constructor
    HasPtr(HasPtr &&p) noexcept : 
        ps(p.ps), i(p.i) {
            p.ps = 0;
    }
    // assignment operator is both the move- and copy-assignment operator
private:
    std::string *ps;
    int i;
};
// HasPtr &HasPtr::operator=(const HasPtr &rhs)
// {
//     auto newps = new std::string(*rhs.ps);
//     delete ps;
//     ps = newps;
//     i = rhs.i;
//     return *this;
// }
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);   // swap the pointers, not the string data
    swap(lhs.i, rhs.i);     // swap the int members
}
// note rhs is passed by value, which means the HasPtr copy constructor
// copies the string in the right-hand operand into rhs
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // swap the contents of the left-hand operand with the local variable rhs
    swap(*this, rhs);   // rhs now points to the memory this object had used
    return *this;       // rhs is destroyed, which deletes the pointer in rhs
}
#endif