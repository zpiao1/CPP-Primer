using namespace std;
template <typename T> void f1(T&);  // argument must be an lvalue
template <typename T> void f2(const T&);    // can take an rvalue
template <typename T> void f3(T&&);
// // invalid code, for illustration purposes only
// void f3<int&>(int& &&); // when T is int&, function parameter is int& &&
// void f3<int&>(int&);    // when T is int&, function parameter collapses to int&
int main()
{
    // calls to f1 uses the referred-to type of the argument as the template parameter type
    f1(i);  // i is an int; template parameter T is int
    f1(ci); // ci is a const int; template paramter T is const int
    f1(5);  // error: argument to a & parameter must be an lvalue
    // parameter in f2 is const &; const in the argument is irrelevant
    // in each of these three calls, f2's function paramter is inferred as const int&
    f2(i);  // i is an int; template parameter T is int
    f2(ci); // ci is a const int, but template parameter T is int
    f2(5);  // a const & parameter can be bound to an rvalue; T is int
    f3(42); // argument is an rvalue of type int; template parameter T is int
    f3(i);  // argument is an lvalue; template parameter T is int&
    f3(ci); // argument is an lvalue; template parameter T is const int&
    return 0;
}