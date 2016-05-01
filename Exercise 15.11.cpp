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
    virtual ~Quote() = default; // dynamic binding for the destructor
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};
class Bulk_quote : public Quote {   // Bulk_quote inherits from Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {}
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const override;
private:
    std::size_t min_qty = 0;    // minimum purchase for the discount to apply
    double discount = 0.0;      // fractional discount to apply
};
using namespace std;
double print_total(ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
void Quote::debug(ostream &os) const
{
    os << "bookNo: " << bookNo << endl;
    os << "price: " << price << endl;
}
void Bulk_quote::debug(ostream &os) const
{
    Quote::debug(os);
    os << "min_qty: " << min_qty << endl;
    os << "discount: " << discount << endl;
}
int main()
{
    Quote item("321-123", 50);
    Bulk_quote bitem("321-123", 50, 10, 0.1);
    item.debug(cout);
    bitem.debug(cout);
    return 0;
}