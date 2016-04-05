#include <iostream>
#include "Sales_item.h"
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<Sales_item> books;
    Sales_item trans;
    while (cin >> trans) 
        books.push_back(trans);
    sort(books.begin(), books.end(), compareIsbn);
    auto beg = books.begin();
    while (beg != books.end()) {
        auto end = find_if(beg, books.end(), [beg](const Sales_item &item) {
            return beg->isbn() != item.isbn();
        } );
        cout << accumulate(beg, end, *beg) << endl;
        beg = end;
    }
}