#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string word;
    string pattern("[^c]ei");
    regex r(pattern);
    smatch results;
    while (cin >> word)
        if (regex_search(word, results, r))
            cout << "Wrong spelling: " + results.str() << endl;
    return 0;
}