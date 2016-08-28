#include "Sales_data.h"
namespace cplusplus_primer {    // reopen cplusplus_primer
// members defined inside the namespace may use unqualified names
std::istream& operator>>(std::istream& in, Sales_data& s) { /* ... */ }
}

// namespace members defined outside the namespace must use qualified names
cplusplus_primer::Sales_data
cplusplus_primer::operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    // ...
}
// we must declare the specialization as a member of std
namespace std {
    template <> struct hash<Sales_data>;
}
// having added the declaration for the specialization to std
// we can define the specialization outside the std namespace
template <> struct std::hash<Sales_data>
{
    size_t operator()(const Sales_data& s) const
    { return hash<string>()(s.bookNo) ^
             hash<unsigned>()(s.units_sold) ^
             hash<double>()(s.revenue); }
    // other members as before
}