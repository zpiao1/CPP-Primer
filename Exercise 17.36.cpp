#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    cout << setw(20) << left << "default format: " << right << 100 * sqrt(2.0) << '\n'
         << setw(20) << left << "scientific: " << right << scientific 
         << 100 * sqrt(2.0) << '\n'
         << setw(20) << left << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << setw(20) << left << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
         << setw(20) << left << "use defaults: " << defaultfloat << 100 * sqrt(2.0) 
         << "\n\n";
    return 0;
}