#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Sales_data {
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);  
public:
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
double Sales_data::avg_price() const
{
    return revenue / units_sold;
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
       << item.revenue << " " << item.avg_price();
    return os;
}

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);    // open the file of sales transactions
    ofstream output(argv[2]);   // open the output file
    Sales_data total;           // variable to hold the running sum
    if (read(input, total)) {   // read the first transaction
        Sales_data trans;       // variable to hold data for the next transaction
        while (read(input, trans)) {    // read the remaining transactions
            if (total.isbn() == trans.isbn())   // check isbns
                total.combine(trans);   // update the running total
            else {
                print(output, total) << endl;   // print the results
                total = trans;          // process the next book
            }
        }
        print(output, total) << endl;   // print the last transaction
    } else
        cerr << "No data?!" << endl;    
    return 0;
}