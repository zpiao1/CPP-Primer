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
    Quote(const Quote &q): bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote copy constructor" << std::endl;
    }
    Quote(Quote &&q): bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
        std::cout << "Quote move constructor" << std::endl;
    }
    Quote& operator=(const Quote&);
    Quote& operator=(Quote&&);
    virtual ~Quote() {
        std::cout << "Quote destructor" << std::endl;
    };
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_policy() const {
        return {quantity, discount};
    }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
        Disc_quote(book, price, qty, disc) {}
    Bulk_quote(const Bulk_quote &bq): Disc_quote(bq) {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }
    Bulk_quote(Bulk_quote &&bq): Disc_quote(std::move(bq)) {
        std::cout << "Bulk_quote move constructor" << std::endl;
    }
    Bulk_quote &operator=(const Bulk_quote &bq);
    Bulk_quote &operator=(Bulk_quote &&bq);
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const override;
    ~Bulk_quote() {
        std::cout << "Bulk_quote destructor" << std::endl;
    }
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
Quote &Quote::operator=(const Quote &rhs)
{
    cout << "Quote copy assignment operator" << endl;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}
Quote &Quote::operator=(Quote &&rhs)
{
    cout << "Quote move assignment operator" << endl;
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
}
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
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    cout << "Bulk_quote copy assignment operator" << endl;
    Disc_quote::operator=(rhs);
    return *this;
}
Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs)
{
    cout << "Bulk_quote move assignment operator" << endl;
    Disc_quote::operator=(rhs);
    return *this;
}
int main()
{
    Quote quote("12345", 10.00);
    Quote quote_copy(quote);
    cout << "====================" << endl;
    Quote quote_move(std::move(quote));
    cout << "====================" << endl;
    quote_copy = quote;
    cout << "====================" << endl;
    quote_move = std::move(quote);
    cout << "====================" << endl;
    Bulk_quote bulk_quote("12345", 10.00, 5, 0.1);
    Bulk_quote bulk_quote_copy(bulk_quote);
    cout << "====================" << endl;
    Bulk_quote bulk_quote_move(std::move(bulk_quote));
    cout << "====================" << endl;
    bulk_quote_copy = bulk_quote;
    cout << "====================" << endl;
    bulk_quote_move = std::move(bulk_quote);
    cout << "====================" << endl;
    return 0;
}