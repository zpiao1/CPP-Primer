#include <tuple>
using namespace std;
int main()
{
    auto item = make_tuple("0-999-78345-X", 3, 20.00);
    typedef decltype(item) trans;   // trans is the type of item
    // returns the number of members in object's of type trans
    size_t sz = tuple_size<trans>::value;   // return 3
    // cnt has the same type as the second member in item
    tuple_element<1, trans>::type cnt = get<1>(item);   // cnt is an int
    return 0;
}