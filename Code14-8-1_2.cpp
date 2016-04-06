#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class SizeComp {
public:
    SizeComp(size_t n): sz(n) {}    // parameter for each captured variable
    // call operator with the same return type, parametes, and body as the lambda
    bool operator()(const string &s) const {
        return s.size() >= sz;
    }
private:
    size_t sz;  // a data member for each variable captured by value
};
int main()
{
    // get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a)
    // get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
    return 0;
}