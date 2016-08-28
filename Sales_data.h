#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>

class Sales_data;
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream&, Sales_data&);
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);
bool eqOp(const Sales_data &lhs, const Sales_data &rhs);
std::ostream &operator<<(std::ostream &os, const Sales_data &item);
std::istream &operator>>(std::istream &is, Sales_data &item);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
bool operator==(const Sales_data &lhs, const Sales_data &rhs);
bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

// template<class T> class std::hash;   // needed for the friend declaration
namespace std {
    template<class T> class hash;
}

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Sales_data &item);
    friend std::istream &operator>>(std::istream &is, Sales_data &item);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
    friend class std::hash<Sales_data>;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    typedef double (Sales_data::*APType)() const;
    inline double avg_price() const {
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
    Sales_data &operator=(const std::string &isbn);
};

namespace std {
template <>
struct hash<Sales_data> {
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator()(const Sales_data& s) const;
};
}

// hypothetical exception classes for a bookstore application
class out_of_stock: public std::runtime_error {
public:
    explicit out_of_stock(const std::string &s):
        std::runtime_error(s) {}
};

class isbn_mismatch: public std::logic_error {
public:
    explicit isbn_mismatch(const std::string &s):
        std::logic_error(s) {}
    isbn_mismatch(const std::string &s,
        const std::string &lhs, const std::string& rhs):
        std::logic_error(s), left(lhs), right(rhs) {}
    const std::string left, right;
};

#endif  // SALES_DATA_H