#include <string>
#include <iostream>
class Quote;    // declared but not defined
// error: Quote must be defined
class Bulk_quote : public Quote { ... };
