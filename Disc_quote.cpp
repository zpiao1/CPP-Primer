#include <iostream>
#include <string>
// class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_policy() const {
        return {quantity, discount};
    } // other members as before
protected:
    std::size_t quantity = 0;   // purchase size for the discount to apply
    double discount = 0.0;      // fractional discount to apply
};