#include <list>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string word;
    list<string> lwords;
    while (cin >> word)
        lwords.push_back(word);
    for (auto iter = lwords.begin(); iter != lwords.end(); ++iter)
        cout << *iter << endl;
    return 0;
}