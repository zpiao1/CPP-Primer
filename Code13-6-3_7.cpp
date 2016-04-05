#include <vector>
#include <algorithm>
using namespace std;
class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const; // error: must have reference qualifier
    // Comp is type alias for the function type (see § 6.7 (p. 249))
    // that can be used to compare int values
    using Comp = bool(const int&, const int&);
    Foo sorted(Comp *); // ok: different parameter list
    Foo sorted(Comp *) const;   // ok: neither version if reference qualified
};