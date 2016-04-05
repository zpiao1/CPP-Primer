#include <string>
using namespace std;
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp);
private:
    std::string *ps;
    int i;
};
HasPtr::HasPtr(const HasPtr &hp):
    ps(new std::string(*(hp.ps))), i(hp.i) {}