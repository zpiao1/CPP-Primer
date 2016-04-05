#include <iostream>
#include <string>
using namespace std;
class Sales_data {
    friend std::istream &read(std::istream &, Sales_data &);
public:
    // nondelegating constructor initailizes members from corresponding arguments
    Sales_data(const std::string s, unsigned cnt, double price):
        bookNo(s), units_sold(cnt), revenue(cnt*price) 
    {
        std::cout << "From constructor Sales_data(const std::string s, unsigned cnt, double price)" << std::endl;
    }
    // remaining constructors all delegate to another constructor
    Sales_data(): Sales_data("", 0, 0) 
    {
        std::cout << "From constructor Sales_data()" << std::endl; 
    }
    Sales_data(const std::string s): Sales_data(s, 0, 0)
    {
        std::cout << "From constructor Sales_data(const std::string s)" << std::endl;
    }
    Sales_data(std::istream &is): Sales_data()
    { 
        read(is, *this); 
        std::cout << "From constructor Sales_data(std::istream &is)" << std::endl;
    }
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
std::istream &read(std::istream &, Sales_data &);
int main()
{
    Sales_data item1 = Sales_data();
    Sales_data item2 = Sales_data("aBook", 3, 15);
    Sales_data item3 = Sales_data("anotherBook");
    Sales_data item4 = Sales_data(std::cin);
    return 0;
}
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}