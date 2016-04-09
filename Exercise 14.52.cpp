#include <iostream>
using namespace std;
class SmallInt {
public:
    SmallInt(int i = 0): val(i)
    {
        cout << "SmallInt::SmallInt()" << endl;
    }  // conversion from int
    operator int() const { return val; }    // conversion to int
private:
    std::size_t val;
};
struct LongDouble {
    LongDouble(double d = 0.0): ld(d) {
        cout << "LongDouble::LongDouble()" << endl;
    }
    operator double() const {
        cout << "LongDouble::operator double()" << endl;
        return static_cast<double>(ld);
    }
    operator float() const {
        cout << "LongDouble::operator float()" << endl;
        return static_cast<float>(ld);
    }
    // member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt& si) {
        cout << "LongDouble::operator+()" << endl;
        ld += static_cast<long double>((int)si);
        return *this;
    }
    long double ld;
};
LongDouble operator+(LongDouble &ld, double d)
{
    cout << "operator+()" << endl;
    ld.ld += static_cast<long double>(d);
    return ld;
}
int main()
{
    SmallInt si;
    LongDouble ld;
    //ld = si + ld;   // ambiguous
    ld = ld + si;
    return 0;
}