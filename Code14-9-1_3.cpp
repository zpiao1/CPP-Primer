#include <exception>
using namespace std;
class SmallInt {
public:
    // the compiler won't automatically apply this conversion
    explicit operator int() const { return val; }
    // other members as before
    SmallInt(int i = 0): val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
private:
    std::size_t val;
};
int main()
{
    SmallInt si = 3;    // ok: the SmallInt constructor is not explicit
    si + 3;             // error: implicit is conversion required, but operator int is explicit
    static_cast<int>(si) + 3;   // ok: explicitly request the conversion
    return 0;
}