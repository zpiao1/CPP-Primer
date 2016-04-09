using namespace std;
class SmallInt;
operator int(SmallInt&);    // error: nonmember
class SmallInt {
public:
    int operator int() const;   // error: return type
    operator int(int = 0) const;    // error: parameter list
    operator int*() const { return 42; }    // error: 42 is not a pointer
}