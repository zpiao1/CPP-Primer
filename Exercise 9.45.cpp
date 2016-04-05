#include <string>
#include <iostream>
using namespace std;
string &insertPreSuf(string &name, const string &prefix, const string &suffix);
int main()
{
    string name("King");
    name = insertPreSuf(name, "Mr.", "I");
    cout << name << endl;
    return 0;
}
string &insertPreSuf(string &name, const string &prefix, const string &suffix)
{
    auto iter = name.begin();
    iter = name.insert(name.begin(), prefix.begin(), prefix.end());
    iter += prefix.size();
    name.insert(iter, 1, ' ');
    name.append(' ' + suffix);
    return name;
}