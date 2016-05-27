#include <iostream>
#include <string>
class Quote {
public:
    Quote() = default;  // = default see § 7.1.4 (p.264)
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual void debug(std::ostream &os) const;
    Quote(const Quote&) = default;  // memberwise copy
    Quote(Quote&&) = default;   // memberwise copy
    Quote& operator=(const Quote&) = default;   // copy assign
    Quote& operator=(Quote&&) = default;    // move assign
    virtual ~Quote() = default; // dynamic binding for the destructor
    // virtual function to return a dynamically allocate copy of itself
    // these members use reference qualifiers; see §13.6.3 (p. 546)
    virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
    }
    // other members as before
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};
using namespace std;
// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
void Quote::debug(ostream &os) const
{
    os << "bookNo: " << bookNo << endl;
    os << "price: " << price << endl;
}
