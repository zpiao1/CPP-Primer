using namespace std;
template <typename T> void f3(T&& val)
{
    T t = val;  // copy or binding a reference?
    t = fcn(t); // does the assignment change only t or val and t?
    if (val == t) { /* ... */ } // always true if T is a reference type
}
template <typename T> void f(T&&);  // binds to nonconst rvalues
template <typename T> void f(const T&); // lvalues and const rvalues