#include <iostream>
#include <string>
using namespace std;
class Quote {
public:
    // virtual destrutor needed if a base pointer pointing to a derived object is deleted
    virtual ~Quote() = default; // dynamic binding for the destructor
};
class Bulk_quote;
int main()
{
    Quote *itemP = new Quote;   // same static and dynamic type
    delete itemP;   // destructor for Quote called
    itemP = new Bulk_quote; // static and dynamic types differ
    delete itemP;   // destructor for Bulk_quote called
    return 0;
}