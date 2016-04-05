#include <string>
#include <iostream>
class Sales_data;
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream&, Sales_data&);
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);
bool eqOp(const Sales_data &lhs, const Sales_data &rhs);
std::ostream operator<<(std::ostream &os, const Sales_data &item);
std::istream operator>>(std::istream &is, Sales_data &item);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream&, Sales_data&);
    friend bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream operator>>(std::ostream os, const Sales_data &item);
    friend std::istream operator>>(std::istream &is, Sales_data &item);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double ave_price() const {
        return units_sold ? revenue / units_sold : 0; 
    }
public:
    Sales_data(std::string s = ""): 
        bookNo(s) {}
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &is) { 
        read(is, *this); 
    }
    Sales_data(const Sales_data &orig):
        bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}
    ~Sales_data() = default;
    Sales_data &operator=(const Sales_data &rhs);
    std::string isbn() const {
        return bookNo;
    }
    Sales_data& combine(const Sales_data&);
    Sales_data &operator+=(const Sales_data &rhs);
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) 
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.ave_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;   // copy data members from lhs into sum
    sum.combine(rhs);
    return sum;
}
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}
