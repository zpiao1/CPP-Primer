#include <iostream>
#include <exception>
using namespace std;
class SmallInt {
public:
    SmallInt(int i = 0): val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
    operator int() const { return val; }
private:
    std::size_t val;
};
int main()
{
    SmallInt si;    
    si = 4; // implicitly converts 4 to SmallInt then calls SmallInt::operator=
    si + 3; // implicitly converts si to int followed by integer addition
    // the double argument is converted to int using the built-in conversion
    SmallInt si = 3.14; // calls the SmallInt(int) constructor
    // the SmallInt conversion operator converts si to int;
    si + 3.14;  // that int is converted to double using the built-in conversion
    return 0;
}