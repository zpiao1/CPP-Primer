#include <tuple>
#include <string>
using namespace std;
int main()
{
    tuple<string, string> duo("1", "2");
    tuple<size_t, size_t> twoD(1, 2);
    bool b = (duo == twoD); // error: can't compare a size_t and a string
    tuple<size_t, size_t, size_t> threeD(1, 2, 3);
    b = (twoD < threeD);    // error: differing number of members
    tuple<size_t, size_t> origin(0, 0);
    b = (origin < twoD);    // ok: b is true
    return 0;
}