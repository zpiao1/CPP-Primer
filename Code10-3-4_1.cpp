#include <vector>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using std::placeholders::_1;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
int main()
{
    // check6 is a callable object that takes one argument of type string
    // and calls check_size on its given string and the value 6
    auto check6 = bind(check_size, _1, 6);
    string s = "hello";
    bool b1 = check6(s);    // check6(s) calls check_size(s, 6);
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a) { return a.size() >= sz; });
    auto wc = find_if(words.begin(), words.end(),
                      bind(check_size, _1, sz);
    return 0;
}