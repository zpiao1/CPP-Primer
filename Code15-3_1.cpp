#include <iostream>
#include <string>
class Quote;
class Bulk_quote;
using namespace std;
double print_total(ostream &os, const Quote &item, size_t n);
int main()
{
    Quote base("0-201-82470-1", 50);
    print_total(cout, base, 10);        // calls Quote::net_price
    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    print_total(cout, derived, 10);     // calls Bulk_quote::net_price
    base = derived;     // copies the Quote part of derived into base
    base.net_price(20); // calls Quote::net_price
    return 0;
}