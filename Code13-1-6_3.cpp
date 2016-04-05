using namespace std;
class PrivateCopy {
    // no access specifier; following members are private by default; see § 7.2 (p. 268)
    // copy control is private and so is inaccessible to ordinary user code
    PrivateCopy(const PrivateCopy &);
    PrivateCopy &operator[](const PrivateCopy &);
    // other members
public:
    PrivateCopy() = default;    // use the synthesized default constructor
    ~PrivateCopy(); // users can define objects of this type but not copy them
};