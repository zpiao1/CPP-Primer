#include <unordered_set>
#include "Sales_data.h"
#include <string>
using namespace std;
size_t hasher(const Sales_data &sd)
{
    return hash<string>() (sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}
using SD_multiset = unordered_multiset<Sales_data, decltype(hasher) *, decltype(eqOp) *>;
int main()
{
    // arguments are the bucket size and pointers to the hash function and equality operator
    SD_multiset bookstore(42, hasher, eqOp);
    return 0;
}