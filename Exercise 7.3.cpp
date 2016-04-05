#include <iostream>
#include <string>
using namespace std;
struct Sales_data {
    // new members: operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged from § 2.6.1 (p. 72)
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// nonmemeber Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


int main()
{
    Sales_data sd1, sd2;
    cout << "Enter bookNo, units_sold, revenue for sd1:" << endl;
    cin >> sd1.bookNo >> sd1.units_sold >> sd1.revenue;
    cout << "Enter bookNo, units_sold, revenue for sd2:" << endl;
    cin >> sd2.bookNo >> sd2.units_sold >> sd2.revenue;
    cout << "sd1.isbn() = " << sd1.isbn() << endl;
    cout << "sd1.avg_price() = " << sd1.avg_price() << endl;
    sd1.combine(sd2);
    cout << "sd1.units_sold = " << sd1.units_sold << endl;
    cout << "sd1.revenue = " << sd1.revenue << endl; 
    cout << "sd1.avg_price() = " << sd1.avg_price() << endl;
    return 0;
}

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;   // add the members of rhs into
    revenue += rhs.revenue;         // the members of "this" object
    return *this;                   // return the object on which the functions was called
}