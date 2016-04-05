#include <iostream>
#include <string>
using namespace std;
class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p * n) {}
    explicit Sales_data(const std::string &s): bookNo(s) {}
    explicit Sales_data(std::istream&);
    // remaining members as before
};
item.combine(null_book);    // error: string constructor is explicit
item.combine(cin);          // error: string constructor is explicit
// error: explicit allowed only on a constructor declaration in a class header
explicit Sales_data::Sales_data(istream& is)
{
    read(is, *this);
}
Sales_data item1 (null_book);   // ok: direct initialization
// error: cannot use the copy form of initialization with an explicit constructor
Sales_data item2 = null_book;