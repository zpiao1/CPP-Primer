#include <iostream>
using namespace std;
template <typename T, unsigned N>
inline T* Begin(T (&arr)[N])
{
    return arr;
}
template <typename T, unsigned N>
inline T* End(T (&arr)[N])
{
    return arr + N;
}
int main()
{
    int iarr[] = {1, 2, 3, 4, 5};
    for (auto iter = Begin(iarr); iter != End(iarr); ++iter)
        cout << *iter << endl;
    return 0;
}