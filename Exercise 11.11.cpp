#include <string>
#include <iostream>
#include <set>
using namespace std;
bool compareIsbn(const Sales_data &, const Sales_data &);
int main()
{
    multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data &)> bookstore;
    return 0;
}