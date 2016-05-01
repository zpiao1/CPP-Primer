#include <iostream>
#include <string>
class Quote;
class Bulk_quote;
using namespace std;
int main()
{
    // calls the version from the base class regardless of the dynamic type of baseP
    double undiscounted = baseP->Quote::net_price(42);
    return 0;
}