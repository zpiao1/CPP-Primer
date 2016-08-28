// ---- user.cc ----
// names in the Sales_data.h header are in the cplusplus_primer namespace 
#include "Sales_data.h"
int main()
{
    using cplusplus_primer::Sales_data;
    Sales_data trans1, trans2;
    // ...
    return 0;
}