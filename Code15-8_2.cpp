#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Quote;
class Disc_quote;
class Bulk_quote;
int main()
{
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    // calls the version defined by Quote: prints 562.5 i.e., 15 * $50 less the discount
    cout << basket.back()->net_price(15) << endl;
    return 0;
}