#include <string>
#include <map>
using namespace std;
int main()
{
    string search_item("Alain de Botton");  // author we'll look for
    auto entries = authors.count(search_item);  // number of elements
    auto iter = authors.find(search_item);  // first entry for this author
    // loop through thr number of entries there are for this author
    while (entries) {
        cout << iter->second << endl;   // print each title
        ++iter;                         // advance to the next title
        --entries;                      // keep track of how many we've printed
    }
    // definitions of authors and search_item as above
    // beg and end denote the range of elements for this author
    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
         beg != end; ++beg)
        cout << beg->second << endl;    // print each title
    // definitions of authors and search_item as above
    // pos holds iterators that denote the range of elements for this key
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl;  // print each title
    return 0;
}