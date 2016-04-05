#include <vector>
using namespace std;
int main()
{
    vector<int> v1(10); // ok: direct initialization
    vector<int> v2 = 10;    // error: constructor that takes a size is explicit
    void f(vector<int>);    // f's parameter is copy initialized
    f(10);                  // error: can't use an explicit constructor to copy an argument
    f(vector<int>(10));     // ok: directly construct a temporary vector from an int
    return 0;
}