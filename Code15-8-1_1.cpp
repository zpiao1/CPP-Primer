#include <iostream>
#include <string>
#include <memory>
#include <vector>
class Quote;
class Disc_quote;
class Bulk_quote;
class Basket;
using namespace std;
int main()
{
    Basket bsk;
    bsk.add_item(make_shared<Quote>("123", 45));
    bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));
    return 0;
}