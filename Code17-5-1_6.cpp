#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    // cout.precision reports the current precision value
    cout << "Precision: " << cout.precision()
         << ", Value: "   << sqrt(2.0) << endl;
    // cout.precision(12) asks that 12 digits of precision be printed
    cout.precision(12);
    cout << "Precision: " << cout.precision()
         << ", Value: "   << sqrt(2.0) << endl;
    // alternative way to set precision using the setprecision manipulator
    cout << setprecision(3);
    cout << "Precision: " << cout.precision()
         << ", Value: "   << sqrt(2.0) << endl;
    return 0;
}