#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>
class Basket {
public:
    // Basket uses synthesized default constructor and copy-control members
    void add_item(const std::shared_ptr<Quote> &sale) {
        items.insert(sale);
    }
    // prints the total price for each book and the overall total for all items in the basket
    double total_receipt(std::ostream &) const;
    void add_item(const Quote& sale)    // copy the given object
    { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote&& sale)         // move the given object
    { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
private:
    // function to compare shared_ptrs needed by the multiset member
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    // multiset to hold multiple quotes, ordered by the compare member
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};
using namespace std;
double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;   // holds the running total
    // iter refers to the first element in a batch of elements with the same ISBN
    // upper_bound returns an iterator to the element just past the end of that batch
    for (auto iter = items.cbegin();
              iter != items.cend();
              iter = items.upper_bound(*iter)) {
        // we know there's at least one element with this key in the Basket
        // print the line item for this book
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;    // print the final overall total
    return sum;
}