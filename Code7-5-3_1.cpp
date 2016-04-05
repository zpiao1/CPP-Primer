#include <string>
using namespace std;
class NoDefault {
public:
    NoDefault(const std::string &);
    // additional members follow, but no other constructors
};
struct A {  // my_mem is public by default; see § 7.2 (p. 268)
    NoDefault my_mem;
};
A a;        // error: cannot synthesize a constructor for A
struct B {
    B() {}  // error: no initializer for b_member
    NoDefault b_member;
};
