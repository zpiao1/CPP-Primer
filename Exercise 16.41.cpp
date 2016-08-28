#include <iostream>
using namespace std;
template <typename T1, typename T2>
auto sum(const T1& v1, const T2& v2) -> decltype(v1 + v2)
{
    return v1 + v2;
}
int main()
{
    int v1 = 1;
    double v2 = 3.5;
    cout << sum(v1, v2) << endl;
    return 0;
}