#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main()
{
    multimap<string, string> authors = {
        {"J.K. Rowling", "Harry Potter I"},
        {"J.K. Rowling", "Harry Potter III"},
        {"J.K. Rowling", "Harry Potter II"},
        {"J.K. Rowling", "Harry Potter V"},
        {"J.K. Rowling", "Harry Potter IV"}};

    for (auto iter = authors.cbegin(); iter != authors.cend(); iter = authors.upper_bound(iter->first)) {
        cout << iter->first << ": " << endl;
        set<string> titles;
        for (auto iter2 = iter; iter2 != authors.upper_bound(iter->first); ++iter2)
            titles.insert(iter2->second);
        for (auto iter3 = titles.cbegin(); iter3 != titles.cend(); ++iter3)
            cout << *iter3 << endl;
    }
    return 0;
}