#include <iostream>
#include <string>
class Quote;
class Disc_quote;
class Bulk_quote;
using namespace std;
int main()
{
    // Disc_quote declares pure virtual functions, which Bulk_quote will override
    Disc_quote discounted;  // error: can't define a Disc_quote object
    Bulk_quote bulk;        // ok: Bulk_quote has no pure virtual functions
    return 0;
}