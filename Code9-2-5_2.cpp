#include <string>
#include <list>
#include <vector>
using namespace std;
int main()
{
    list<string> names;
    vector<const char*> oldstyle;
    names = oldstyle;   // error: container types don't match
    // ok: can convert from const char* to string
    names.assign(oldstyle.cbegin(), oldstyle.cend());
    // equivalent to slist1.clear();
    // followed by slist1.insert(slist1.begin(), 10, "Hiya!");
    list<string> slist1(1); // one element, which is the empty string
    slist1.assign(10, "Hiya!"); // ten elements; each one if Hiya!
    return 0;
}