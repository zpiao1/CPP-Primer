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
    name.insert(0, prefix + ' ');
    name.insert(name.size(), ' ' + suffix);
    return name;
}