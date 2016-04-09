#include <iostream>
using namespace std;
class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int i = 0): val(i)
    {
        cout << "SmallInt::SmallInt()" << endl;
    }  // conversion from int
    operator int() const { 
        cout << "SmallInt::operator int()" << endl;
        return val; 
    }    // conversion to int
private:
    std::size_t val;
};
SmallInt operator+(const SmallInt& lhs, const SmallInt &rhs)
{
    cout << "operator+()" << endl;
    return lhs;
}
int main()
{
    SmallInt s1;
    double d = s1 + 3.14; // ambiguous
    return 0;
}