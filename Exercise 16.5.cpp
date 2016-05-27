#include <iostream>
using namespace std;
template <unsigned N, typename T>
void print(T (&arr)[N])
{
    for (T val : arr)
        cout << val << endl;
}
int main()
{
    int iarr[] = {1,2,3,4,5};
    char cstr[] = {'H', 'e', 'l', 'l', 'o'};
    print(iarr);
    print(cstr);
    return 0;
}