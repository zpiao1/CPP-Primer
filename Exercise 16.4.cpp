#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
template <class InputIterator, class T>
InputIterator Find(InputIterator first, InputIterator last, const T& val)
{
    for (InputIterator iter = first; iter != last; ++iter)
        if (*iter == val)
            return iter;
    return last;
}
int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    list<string> ls{"hello", "world", "thank", "you"};
    auto viter = Find(vi.cbegin(), vi.cend(), 5);
    if (viter != vi.cend())
        cout << *viter << endl;
    else
        cout << "Not found" << endl;
    auto liter = Find(ls.cbegin(), ls.cend(), "me");
    if (liter != ls.cend())
        cout << *liter << endl;
    else
        cout << "Not found" << endl;
    return 0;
}