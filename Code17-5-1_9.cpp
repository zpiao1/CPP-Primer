#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i = -16;
    double d = 3.14159;
    // pad the first column to use a minimum of 12 positions in the output
    cout << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n';
    // pad the first column and left-justify all columns
    cout << left
         << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n'
         << right;
    // pad the first column and right-justify all columns
    cout << right
         << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n';
    // pad the first column but put the padding internal to the field
    cout << internal
         << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n';
    // pad the first column, using # as the pad character
    cout << setfill('#')
         << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n'
         << setfill(' ');   // restore the normal pad character
    return 0;
}