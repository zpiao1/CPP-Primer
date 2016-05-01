#include <iostream>
#include <string>
class Book {
private:
    std::string name;
protected:
    double price;
public:
    Book(std::string bookName = "", double p = 0.0):
        name(bookName), price(p) {}
    virtual double net_price(std::size_t num) const {
        return price * num;
    }
    virtual ~Book() = default;
};
class DiscountedBook : public Book {
private:
    std::size_t limit;
    double discount_rate;
public:
    DiscountedBook(std::string bookName = "", double p = 0.0, std::size_t bookLimit = 0, double dr = 1):
        Book(bookName, p), limit(bookLimit), discount_rate(dr) {}
    double net_price(std::size_t num) const override {
        double ret = price * num;
        if (num >= limit)
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