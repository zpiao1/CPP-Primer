#include "Sales_data.h"
#include <unordered_set>
// open the std namespace so we can specialize std::hash
namespace std {
template <> // we're defining a specialization with
struct hash<Sales_data> // the template parameter of Sales_data
{
    // the type used to hash an unordered container must define these types
    typedef size_t result_type;
    typedef Sales_data argument_type;   // by default, this type needs ==
    size_t operator()(const Sales_data& s) const;
    // our class uses synthesized copy control and default constructor
};
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
    return hash<string>()(s.bookNo) ^
           hash<unsigned>()(s.units_sold) ^
           hash<double>()(s.revenue);
}
}   // close the std namespace; note: no semicolon after the close curly

using namespace std;
int main()
{
    // uses hash<Sales_data> and Sales_data operator== from § 14.3.1 (p.561)
    unordered_multiset<Sales_data> SDset;
    return 0;
}