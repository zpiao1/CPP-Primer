#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1) / sizeof(*a1)];   // a2 has the same size as a1
    // ret points just past the last element copied into a2
    auto ret = copy(begin(a1), end(a1), a2);    // copy a1 to a2;
    return 0;
}