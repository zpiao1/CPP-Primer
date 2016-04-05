#include <string>
using namespace std;
class Sales_data {
public:
    // copy control; use defaults
    Sales_data() = default;
    Sales_data(const Sales_data &) = default;
    Sales_data& operator=(const Sales_data);
    ~Sales_data() = default;
    // other members as before
};
Sales_data &Sales_data::operator=(const Sales_data &) = default;