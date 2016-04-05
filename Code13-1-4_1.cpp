#include <string>
using namespace std;
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    ~HasPtr() {
        delete ps;
    }
    // WRONG: HasPtr needs a copy constructor and copy-assignment operator
    // other members as before
};

HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
    HasPtr ret = hp;    // copies the given HasPtr
    // process ret
    return ret; // ret and hp are destroyed
}

int main()
{
    Hasptr p("some values");
    f(p);   // when f completes, the memory to which p.ps points is freed
    HasPtr q(p);    // now both p and q point to invalid memory!
    return 0;
}