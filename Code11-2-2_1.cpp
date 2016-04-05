#include <iostream>
#include <string>
#include <set>
using namespace std;
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    // bookstore can have several transactions with the same ISBN
    // elements in bookstore will be in ISBN order
    multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);
    return 0;
}