#include <iostream>
#include <string>
#include <memory>
#include <set>
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
    virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
    }
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
    Bulk_quote* clone() const & override {
        return new Bulk_quote(*this);
    }
    Bulk_quote* clone() && override {
        return new Bulk_quote(std::move(*this));
    }
};
class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale) {
        items.insert(sale);
    }
    double total_receipt(std::ostream &) const;
    void add_item(const Quote& sale)
    { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote&& sale)
    { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
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
double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin();
              iter != items.cend();
              iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}
int main()
{
    Basket basket;
    basket.add_item(Quote("0-201-82470-1", 50));
    for (int i = 0; i < 15; ++i)
        basket.add_item(Bulk_quote("0-201-54848-8", 50, 10, .25));
    basket.total_receipt(cout);
    return 0;
}