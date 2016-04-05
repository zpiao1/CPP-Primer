#include <vector>
using namespace std;
int main()
{
    // construct a Sales_data object at the end of c
    // uses the three-argument Sales_data constructor
    c.emplace_back("978-0590353403", 25, 15.99);
    // error: there is no version of push_back that takes three arguments
    c.push_back("978-0590353403", 25, 15.99);
    // ok: we create a temporary Sales_data object to pass to push_back
    c.push_back(Sales_data("978-0590353403", 25, 15.99));
    // iter refers to an element in c, which holds Sales_data elements
    c.emplace_back();   // uses the Sales_data default constructor
    c.emplace(iter, "999-999999999");   // uses Sales_data(string)
    // uses the Sales_data constructor that takes an ISBN, a count, and a price
    c.emplace_front("978-0590353403", 25, 15.99);
    return 0;
}