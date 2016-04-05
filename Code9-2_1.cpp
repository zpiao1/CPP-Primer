#include <list>
#include <deque>
#include <vector>
#include <string>
using namespace std;
int main()
{
    list<Sales_data>                // list that holds Sales_data objects
    dequq<double>                   // deque that holds doubles
    vector<vector<string>> lines;   // vector of vectors
    // assume noDefault is a type without a default constructor
    vector<noDefault> v1(10, init); // ok: element initializer supplied
    vector<noDefault> v2(10);       // error: must supply an element initializer
}