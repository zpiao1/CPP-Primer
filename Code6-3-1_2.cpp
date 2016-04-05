#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> process()
{
    // ...
    // expected and actual are strings
    if (expected.empty())
        return {};  // return an empty vector
    else if (expected == actual)
        return ("functionX", "okay");   // return list-initialized vector
    else
        return ("functionX", expected, actual);
}
char &get_val(string &str, string::size_type ix)
{
    return str[ix]; // get_val assumes the given index is valid
}

int main()
{
    string s("a value");
    cout << s << endl;      // prints a value
    get_val(s, 0) = 'A';    // changes s[0] to A
    cout << s << endl;      // prints A value
    return 0;
}