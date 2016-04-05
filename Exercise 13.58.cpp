#include <algorithm>
#include <iostream>
#include <vector>
#define NONRECUR
using namespace std;
class Foo {
public:
    Foo() = default;
    Foo(const Foo &f):
        data(f.data) {}
    Foo sorted() const &;
    Foo sorted() &&;
private:
    vector<int> data;
};
Foo Foo::sorted() const & {
#if defined (RECUR)
    cout << "Infinite recursion" << endl;
    Foo ret(*this);
    return ret.sorted();
#elif defined (NONRECUR)
    cout << "Works properly" << endl;
    return Foo(*this).sorted();
#endif
}
Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    return *this;
}
int main()
{
    Foo f;
    f.sorted();
    return 0;
}