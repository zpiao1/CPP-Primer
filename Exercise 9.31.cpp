#include <iostream>
#include <list>
#include <forward_list>
using namespace std;
int main()
{
    list<int> li = {0,1,2,3,4,5,6,7,8,9};
    forward_list<int> fi = {0,1,2,3,4,5,6,7,8,9};
    auto liter = li.begin();
    auto prev = fi.before_begin();
    auto curr = fi.begin();
    while (liter != li.end()) {
        if (*liter % 2) {
            liter = li.insert(liter, *liter);
            ++liter;
            ++liter;
        } else
            liter = li.erase(liter);
    }
    while (curr != fi.end()) {
        if (*curr % 2) {
            prev = fi.insert_after(curr, *curr);
            ++curr;
            ++curr;
        } else {
            curr = fi.erase_after(prev);
            prev = curr;
        }
    }
    for (auto i : li)
        cout << i << ' ';
    cout << endl;
    for (auto i : fi)
        cout << i << ' ';
    cout << endl;
    return 0;
}
