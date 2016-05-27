#include <iostream>
#include <string>
class Book {
private:
    std::string name = "";
protected:
    double price = 0.0;
public:
    Book(std::string bookName = "", double p = 0.0):
        name(bookName), price(p) {}
    virtual double net_price(std::size_t qty) const {
        return price * qty;
    }
    virtual ~Book() = default;
};
class Disc_quote : public Book {
public:
    Disc_quote(std::string bookName = "", double p = 0.0, std::size_t lim = 0, double disc_rate = 1.0):
        Book(bookName, p), limit(lim), discount_rate(disc_rate) {}
    double net_price(std::size_t qty) const = 0; 
protected:
    std::size_t limit = 0;
    double discount_rate = 1.0;
};
class DiscountedBook : public Disc_quote {
public:
    DiscountedBook(std::string bookName = "", double p = 0.0, std::size_t bookLimit = 0, double dr = 1):
        Disc_quote(bookName, p, bookLimit, dr) {}
    double net_price(std::size_t qty) const override {
        double ret = price * qty;
        if (qty >= limit)
            ret *= discount_rate;
        return ret;
    }
};
using namespace std;
int main()
{
    Book b("Book", 50);
    DiscountedBook db("DiscountedBook", 50, 3, 0.8);
    cout << b.net_price(10) << endl;
    cout << db.net_price(10) << endl;
    return 0;
}