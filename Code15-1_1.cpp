#include <iostream>
#include <string>
class Quote {
public:
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
};
class Bulk_quote : public Quote {   // Bulk_quote inherits from Quote
public:
    double net_price(std::size_t) const override;
};
using namespace std;
// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()   // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
int main()
{
    // basic has type Quote; bulk has type Bulk_quote
    print_total(cout, basic, 20);   // calls Quote version of net_price
    print_total(cout, bulk, 20);    // calls Bulk_quote version of net_price
    return 0;
}