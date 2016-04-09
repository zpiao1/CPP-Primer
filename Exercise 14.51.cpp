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
void calc(int)
{
    cout << "calc(int)" << endl;
}
void calc(LongDouble)
{
    cout << "calc(LongDouble)" << endl;
}
int main()
{
    double dval;
    calc(dval);
    return 0;
}