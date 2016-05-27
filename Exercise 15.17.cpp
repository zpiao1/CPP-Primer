#include <iostream>
#include <string>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual void debug(std::ostream &os) const;
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
        Quote(book, price), min_qty(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t min_qty = 0; 
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
        Disc_quote(book, price, qty, disc) {}
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const override;
};

using namespace std;
double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
void Quote::debug(ostream &os) const
{
    os << "bookNo: " << bookNo << endl;
    os << "price: " << price << endl;
}
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
void Bulk_quote::debug(ostream &os) const
{
    Quote::debug(os);
    os << "min_qty: " << min_qty << endl;
    os << "discount: " << discount << endl;
}
int main()
{
    Disc_quote disc_quote;
    return 0;
}