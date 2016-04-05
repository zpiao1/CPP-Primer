#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    // get an iterator to an element in word_count
    auto map_it = word_count.begin();
    // *map_it is a reference to a pair<const string, size_t> object
    cout << map_it->first;              // prints the key for this element
    cout << " " << map_it->second;      // prints the value of the element
    map_it->first = "new key";          // error: key is const
    ++map_it->second;                   // ok: we can chage the value through an iterator
    return 0;
}