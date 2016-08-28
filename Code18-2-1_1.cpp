namespace cplusplus_primer {
    class Sales_data { /* ... */ };
    Sales_data { /* ... */ };
    Sales_data operator+(const Sales_data&, const Sales_data&);
    class Query { /* ... */ };
    class Query_base { /* ... */ };
}   // like blocks, namespaces do not end with a semicolon
int main()
{
    cplusplus_primer::Query q = cplusplus_primer::Query("hello");
    AddisonWesley::Query q = AddisonWesley::Query("hello");
    return 0;
}