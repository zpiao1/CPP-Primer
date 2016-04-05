#include <vector>
#include <iostream>
using namespace std;
vector<int> *buildVector();
void giveValues(vector<int> *);
void printValues(const vector<int> *);
int main()
{
    auto pvi = buildVector();
    giveValues(pvi);
    printValues(pvi);
    delete pvi;
    return 0;
}
vector<int> *buildVector()
{
    auto pvi = new vector<int>();
    return pvi;
}

void giveValues(vector<int> *pvi)
{
    int i;
    while (cin >> i)
        pvi->push_back(i);
}

void printValues(const vector<int> *pvi)
{
    for (auto i : *pvi)
        cout << i << ' ';
    cout << endl;
}