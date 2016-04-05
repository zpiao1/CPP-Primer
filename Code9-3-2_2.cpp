#include <container>
using namespace std;
int main()
{
    if (!c.empty()) {
        c.front() = 42;     // assigns 42 to the first element in c
        auto &v = c.back(); // get a reference to the last element
        v = 1024;           // changes the element in c
        auto v2 = c.back(); // v2 is not a reference; it's a copy of c.back()
        v2 = 0;             // no change to the element in c
    }
    return 0;
}