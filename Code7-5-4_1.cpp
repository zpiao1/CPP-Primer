#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;
string null_book = "9-999-99999-9";
// constructs a temporary Sales_data object
// with units_sold and revenue equal to 0 and bookNo equal to null_book
item.combine(null_book);
// error: requires two user-defined conversions:
//  (1) convert "9-999-99999-9"  to string
//  (2) convert that (temporary) string to Sales_data
item.combine("9-999-99999-9");
// ok: explicit conversion to string, implicit conversion to Sales_data
item.combine(string("9-999-99999-9"));
// ok: implicit conversion to string, explicit conversion to Sales_data
item.combine(Sales_data("9-999-99999-9"));
// uses the istream constructor to build an object to pass to combine
item.combine(cin);
