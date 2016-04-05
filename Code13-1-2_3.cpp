#include <string>
using namespace std;
// equivalent to the synthesized copy-assignment operator
Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;            // calls the string::operator=
    units_sold = rhs.units_sold;    // uses the built-in int assignment
    revenue = rhs.revenue;          // uses the built-in double assignment
    return *this;                   // return a reference to this object
}