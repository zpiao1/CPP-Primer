#include <utility>
using namespace std;
// original, most general template
template <class T> struct remove_reference {
    typedef T type;
};
// partial specializations that will be used for lvalue and rvalue
template <class T> struct remove_reference<T&>  // lvalue references
{ typedef T type; }
template <class T> struct remove_reference<T&&> // rvalue references
{ typedef T type; }

int main()
{
    int i;
    // decltype(42) is int, uses the original template
    remove_reference<decltype(42)>::type a;
    // decltype(i) is int&, uses first(T&) partial specialization
    remove_reference<decltype(i)>::type b;
    // decltype(std::move(i)) is int&&, uses second (i.e., T&&)
    remove_reference<decltype(std::move(i))>::type c;
    return 0;
}