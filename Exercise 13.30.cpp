#include <iostream>
#include <string>
using namespace std;
class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
    friend void print(const HasPtr &);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp):
        ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &rhs);
    HasPtr &operator=(HasPtr rhs);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newps = new std::string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);   // swap the pointers, not the string data
    swap(lhs.i, rhs.i);     // swap the int members
    cout << "inline void swap(HasPtr &lhs, HasPtr &rhs)" << endl;
}
// note rhs is passed by value, which means the HasPtr copy constructor
// copies the string in the right-hand operand into rhs
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // swap the contents of the left-hand operand with the local variable rhs
    swap(*this, rhs);   // rhs now points to the memory this object had used
    return *this;       // rhs is destroyed, which deletes the pointer in rhs
}
void print(const HasPtr &hp)
{
    cout << *hp.ps << ' ' << hp.i << endl;
}
int main()
{
    HasPtr hp1("hello"), hp2("world");
    swap(hp1, hp2);
    print(hp1);
    print(hp2);
    return 0;
}