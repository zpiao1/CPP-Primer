#include "Sales_data.h"
#include <algorithm>
#include <vector>
using namespace std;

struct matches {
    vector<Sales_data>::size_type s;
    vector<Sales_data>::const_iterator b;
    vector<Sales_data>::const_iterator e;
    matches(const vector<Sales_data>::size_type& size, const vector<Sales_data>::const_iterator& begin, const vector<Sales_data>::const_iterator& end):
        s(size), b(begin), e(end) {}
};

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(matches(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}