#include "Sales_data.h"
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<vector<Sales_data>::size_type,
             pair<vector<Sales_data>::const_iterator, 
                  vector<Sales_data>::const_iterator>> matches;
vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<macthes> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(make_pair(it - files.cbegin(), found));
    }
    return ret;
}
