#include <vector>
#include <iostream>
#include <memory>
using namespace std;
shared_ptr<vector<int>> buildVector();
void giveValues(shared_ptr<vector<int>>);
void printValues(const shared_ptr<vector<int>>);
int main()
{
    auto pvi = buildVector();
    giveValues(pvi);
    printValues(pvi);
    return 0;
}
shared_ptr<vector<int>> buildVector()
{
    auto pvi = make_shared<vector<int>>();
    return pvi;
}

void giveValues(shared_ptr<vector<int>> pvi)
{
    int i;
    while (cin >> i)
        pvi->push_back(i);
}

void printValues(const shared_ptr<vector<int>> pvi)
{
    for (auto i : *pvi)
        cout << i << ' ';
    cout << endl;
}