#include <string>
#include <iostream>
#include <memory>
using namespace std;
int main()
{
    allocator<string> allocstr;
    size_t n;
    cin >> n;
    auto const p = allocstr.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && q != p + n)
        allocstr.construct(q++, s);
    const size_t size = q - p;
    for (size_t i = 0; i != size; ++i)
        cout << *(p + i) << endl;
    while (q != p)
        allocstr.destroy(--q);
    allocstr.deallocate(p, n);
    return 0;
}