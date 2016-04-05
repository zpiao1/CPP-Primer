#include <string>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    string sum = accumulate(v.cbegin(), v.cend(), string(""));
    // error: no + on const char*
    string sum = accumulate(v.cbegin(), v.cend(), "");
    return 0;
}