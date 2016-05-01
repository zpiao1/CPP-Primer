#include <iostream>
#include <string>
class Quote;
class Bulk_quote;
int main()
{
    Bulk_quote bulk;
    Quote *itemP = &bulk;       // ok: dynamic type is Bulk_quote
    Bulk_quote *bulkP = itemP;  // error: can't convert base to derived
    return 0;
}