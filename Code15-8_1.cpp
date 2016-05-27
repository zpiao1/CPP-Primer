#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Quote;
class Disc_quote;
class Bulk_quote;
int main()
{
    vector<Quote> basket;
    basket.push_back(Quote("0-201-82470-1", 50));
    // ok, but copies only the Quote part of the object into basket
    basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
    // calls version defined by Quote, prints 750, i.e., 15 * $50
    cout << basket.back().net_price(15) << endl;
    return 0;
}