#include "Sales_data.h"
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
// matches has three members: an index of a store and iterators into that store's vector
typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator> matches;
// files holds the transactions for every store
// findBook returns a vector with an entry for each store that sold the given book
vector<matches>
findBook(const vector<vector<Sales_data>> &files,
         const string &book)
{
    vector<matches> ret;    // initially empty
    // for each store find the range of matching books, if any
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        // find the range of Sales_data that have the same ISBN
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)    // this store had sales
            // remeber the index of this sotre and the matching range
            ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
    }
    return ret; // empty if no matches found
}

void reportResults(istream &in, ostream& os, const vector<vector<Sales_data>> &files)
{
    strings s;  // book to look for
    while (in >> s) {
        auto trans = findBook(files, s);    // stores that sold this book
        if (trans.empty()) {
            cout << s << " not found in any stores" << endl;
            continue;   // get the next book to look for
        }
        for (const auto &store : trans) // for every store with a sale
            // get<n> returns the specified member from the tuple in store
            os << "store " << get<0>(store) << " sales: "
               << accumulate(get<1>(store), get<2>(store), Sales_data(s))
               << endl;
    }
}
int main()
{
    // each element in files holds the transactions for a particular store
    vector<vector<Sales_data>> files;
    return 0;
}