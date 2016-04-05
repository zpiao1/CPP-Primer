#include <string>
Sales_data obj();   // ok: but defines a function, not an object
if (obj.isbn() == Primer_5th_ed.isbn()) // error: obj is a function
// ok: obj is a default-initialized object
Sales_data obj;