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
    for (typename T::size_type i = 0; i != container.size(); ++i)
        cout << container[i] << ' ';
    cout << endl;
}