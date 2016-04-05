#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    transform(vi.begin(), vi.end(), vi.begin(), 
              [](int i) { return i < 0 ? -i : i; });
    // error: cannot deduce the return type for the lambda
    transform(vi.begin(), vi.end(), vi.begin(),
              [](int i) { if (i < 0) return -i; else return i; });
    transform(vi.begin(), vi.end(), vi.begin(),
              [](int i) -> int
              { if (i < 0)  return -i; else return i; });
    return 0;
}