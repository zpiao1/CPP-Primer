using namespace std;
template <typename Foo> Foo calc(const Foo& a, const Foo& b)
{
    Foo tmp = a;    // tmp has the same type as the parameters and return type
    // ...
    return tmp;     // return type and parameters have the same type
}
typedef double A;
template <typename A, typename B> void f(A a, B b)
{
    A tmp = a;  // tmp has same type as the template parameter A, not double
    double B;   // error: redeclares template parameter B
}
// error: illegal reuse of template parameter name V
template <typename V, typename V>   // ...
// declares but does not define compare and Blob
template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;
// all three uses of calc refer to the same function template
template <typename T> T calc(const T&, const T&);   // declaration
template <typename U> U calc(const U&, const U&);   // declaration
// definition of the template
template <typename Type>
Type calc(const Type& a, const Type& b) { /* ... */ }