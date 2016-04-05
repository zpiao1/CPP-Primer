#include <unordered_set>
using namespace std;
int main()
{
    // use FooHash to generate the hash code; Foo must have an == operator
    unordered_set<Foo, decltype(Foohash)*> fooset(10, FooHash);
    return 0;
}