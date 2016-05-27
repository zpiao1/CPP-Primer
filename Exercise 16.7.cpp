#include <iostream>
using namespace std;
template <typename T, unsigned N>
constexpr size_t get_size(T (&arr)[N])
{
    return N;
}
int main()
{
    int iarr[] = {1,2,3,4,5};
    cout << get_size(iarr) << endl;
    return 0;
}