#include <deque>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string word;
    deque<string> qwords;
    while (cin >> word)
        qwords.push_back(word);
    for (auto iter = qwords.begin(); iter != qwords.end(); ++iter)
        cout << *iter << endl;
    return 0;
}