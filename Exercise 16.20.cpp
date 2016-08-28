#include <iostream>
#include <vector>
using namespace std;
template <class T>
void print_all(const T& container);
int main()
{
    vector<int> vi{1,3,5,7,9};
    print_all(vi);
    return 0;
}
template <class T>
void print_all(const T& container)
{
    for (typename T::const_iterator iter = container.cbegin(); iter != container.cend(); ++iter)
        cout << *iter << ' ';
    cout << endl;
}