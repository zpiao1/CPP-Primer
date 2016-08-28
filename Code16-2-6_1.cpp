#include <type_traits>
#include <string>
using namespace std;
// for the use of typename in the return type and the cast see § 16.1.3 (p. 170)
// remove_reference is covered in § 16.2.3 (p. 684)
template <typename T>
typename remove_reference<T>::type&& move(T&& t)
{
    // static_cast covered in § 4.11.3 (p. 163)
    return static_cast<typename remove_reference<T>::type&&>(t);
}
int main()
{
    string s1("hi!"), s2;
    s2 = std::move(string("bye!")); // ok: moving from an rvalue
    s2 = std::move(s1); // ok: but after the assignment s1 has indeterminate value
    return 0;
}