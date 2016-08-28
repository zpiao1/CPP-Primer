#include "Sales_data.h"
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// assume Sales_data::avg_price is public
Sales_data& avgPriceHigher(vector<Sales_data>& svec, double price)
{
    auto it = find(svec.begin(), svec.end(), [price](const Sales_data& item)
        { return item.avg_price() > price; });
    return *it;
}