#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> svec1(10);   // vector with ten elements
    vector<string> svec2(24);   // vector with 24 elements
    swap(svec1, svec2);
    return 0;
}