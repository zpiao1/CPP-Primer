#include <iostream>
#include <string>
#include "Chapter6.h"
using namespace std;
int main()
{
    string s1 = "success";
    string s2 = "failure";
    cout << make_plural(1, s1) << endl;
    cout << make_plural(2, s1) << endl;
    cout << make_plural(1, s2) << endl;
    cout << make_plural(2, s2) << endl;
    return 0;
}
// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}