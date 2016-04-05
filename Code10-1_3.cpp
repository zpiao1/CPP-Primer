#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int ia[] = {27, 210, 12, 47, 109, 83};
    int val = 83;
    int* result = find(begin(ia), end(ia), val);
    // search the elements starting from ia[1] up to but not including ia[4]
    auto result = find(ia + 1, ia + 4, val);
    return 0;
}