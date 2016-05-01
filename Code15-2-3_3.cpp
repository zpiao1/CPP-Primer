#include <iostream>
#include <string>
class Quote;
class Bulk_quote;
int main()
{
    Bulk_quote bulk;    // object of derived type
    Quote item(bulk);   // uses the Quote::Quote(const Quote&) constructor
    item = bulk;        // calls Quote::operator=(const Quote&)
    return 0;
}