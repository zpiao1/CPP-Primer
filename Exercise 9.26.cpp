#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    vector<int> vi;
    list<int> li;
    for (auto i : ia) {
        vi.push_back(i);
        li.push_back(i);
    }
    auto vit = vi.begin();
    auto lit = li.begin();
    while (vit != vi.end()) 
        if (*vit % 2)
            ++vit;
        else
            vit = vi.erase(vit);
    while (lit != li.end())
        if (*lit % 2)
            lit = li.erase(lit);
        else
            ++lit;
    cout << "vi: " << endl;
    for (auto i : vi)
        cout << i << ' ';
    cout << endl << "li: " << endl;
    for (auto i : li)
        cout << i << ' ';
    cout << endl;
    return 0;
}
