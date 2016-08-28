#include <string>
using namespace std;
template <typename T> int compare(const T&, const T&);
// overloaded versions of func; each takes a different function pointer type
void func(int(*)(const string&, const string&));
void func(int(*)(const int&, const int&));
int main()
{
    // pf1 points to the instantiation int compare(const int&, const int&)
    int (*pf1)(const int&, const int&) = compare;
    func(compare);  // error: which instantiation of compare?
    // ok: explicitly specify which version of compare to instantiate
    func(compare<int>); // passing compare(const int&, const int&)
    return 0;
}