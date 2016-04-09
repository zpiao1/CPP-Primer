#include <iostream>
using namespace std;
struct LongDouble {
    LongDouble(double d = 0.0): ld(d) {
        cout << "LongDouble() constructor" << endl;
    }
    operator double() const {
        cout << "LongDouble double() conversion operator" << endl;
        return static_cast<double>(ld);
    }
    operator float() const {
        cout << "LongDouble float() conversion operator" << endl;
        return static_cast<float>(ld);
    }
    long double ld;
};
int main()
{
    LongDouble ldObj;
    //int ex1 = ldObj;    // The conversion is ambiguous
    float ex2 = ldObj;
    return 0;
}