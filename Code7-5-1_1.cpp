#include <string>
using namespace std;
string foo = "Hello World!";    // define and initialize
string bar;                     // default initialized to the empty string
bar = "Hello World!";           // assign a new value to bar
class Sales_data {
public:
    Sales_data(const string &s, unsigned cnt, double price);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    revenue = cnt * price;
};
// legal but sloppier way to write the Sales_data constructor: no constructor initializers
Sales_data::Sales_data(const string &s, unsigned cnt, double price)
{
    bookNo = s;
    units_sold = cnt;
    revenue = cnt * price;
}