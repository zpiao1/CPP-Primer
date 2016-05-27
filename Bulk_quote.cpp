#include <iostream>
#include <string>
// the discount kicks in when a specified number of copies of the same book are sold
// the discount is expressed as a fraction to use to reduce the normal price
class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;   // inherit Disc_quote's constructors
    // Bulk_quote() = default;
    // Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
    //     Disc_quote(book, price, qty, disc) {}
    // overrides the base version to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const override;
    Bulk_quote* clone() const & override {
        return new Bulk_quote(*this);
    }
    Bulk_quote* clone() && override {
        return new Bulk_quote(std::move(*this));
    }
    // other members as before
};
// class Bulk_quote : public Quote {   // Bulk_quote inherits from Quote
// public:
//     Bulk_quote() = default;
//     Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
//         Quote(book, p), quantity(qty), discount(disc) {}
//     // overrides the base version in order to implement the bulk purchase discount policy
//     double net_price(std::size_t) const override;
//     void debug(std::ostream &os) const override;
// private:
//     std::size_t quantity = 0;    // minimum purchase for the discount to apply
//     double discount = 0.0;      // fractional discount to apply
// };
using namespace std;
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
void Bulk_quote::debug(ostream &os) const
{
    Quote::debug(os);
    os << "quantity: " << quantity << endl;
    os << "discount: " << discount << endl;
}