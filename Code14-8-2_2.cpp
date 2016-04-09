#include <string>
#include <vector>
#include <functional>
#include <vector>
using namespace std;
int main()
{
    // passes a temporary function object that applies the > operator to two strings
    sort(svec.begin(), svec.end(), greater<string>());
    vector<string *> nameTable; // vector of pointers
    // error: the pointers in nameTable are unrelated, so < is undefined
    sort(nameTable.begin(), nameTable.end(), 
        [](string *a, string *b) { return a < b; });
    // ok: library guarantees that less on pointer types is well defined
    sort(nameTable.begin(), nameTable.end(), less<string *>());
    return 0;
}