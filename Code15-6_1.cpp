#include <iostream>
#include <string>
class Quote;
class Disc_quote;
class Bulk_quote;
using namespace std;
int main()
{
    Bulk_quote bulk;
    Bulk_quote *bulkP = &bulk;  // static and dynamic types are the same
    Quote *itemP = &bulk;       // static and dynamic types differ
    bulkP->discount_policy();   // ok: bulkP has type Bulk_quote*
    itemP->discount_policy();   // error: itemP has type Quote*
    return 0;
}