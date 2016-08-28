using namespace std;
// Args is a template parameter pack; rest is a function parameter pack
// Args represents zero or more template type parameters
// rest represents zero or more function parameters
template <typename T, typename... Args>
void foo(const T&, const Args& ... rest);
int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d);   // three parameters in the pack
    foo(s, 42, "hi");   // two parameters in the pack
    foo(d, s);  // one parameter in the pack
    foo("hi");  // empty pack;
    return 0;
}
// instantiation for the 4 function calls
// void foo(const int&, const string&, const int*, const double&);
// void foo(const string&, const int&, const char[3]&);
// void foo(const double&, const string&);
// void foo(const char[3]&);