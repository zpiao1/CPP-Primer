#include <iostream>
using namespace std;
int main()
{
    auto f = [] { return 42; };
    cout << f() << endl;    // prints 42
    [](const string &a, const string &b)
      { return a.size() < b.size();}
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(), 
        [](const string &a, const string &b)
          { return a.size() < b.size(); });
}