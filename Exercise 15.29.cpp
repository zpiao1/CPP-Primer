#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;
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
    using Disc_quote::Disc_quote;
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
int main()
{
    double sum = 0;
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    for (const auto &q : basket)
        sum += q->net_price(15);
    cout << "Sum = " << sum << endl;
    return 0;
}