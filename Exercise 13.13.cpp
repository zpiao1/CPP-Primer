#include <iostream>
#include <vector>
using namespace std;
struct X {
    X();
    X(const X&);
    X &operator=(const X&);
    ~X();
};
X::X()
{
    std::cout << "X()" << std::endl;
}
X::X(const X& orig)
{
    std::cout << "X(const X&)" << std::endl;
}
X &X::operator=(const X& rhs)
{
    std::cout << "X &operator=(const X&)" << std::endl;
    return *this;
}
X::~X()
{
    std::cout << "~X()" << std::endl;
}
void nonref(X);
void ref(const X&);
int main()
{
    cout << "X x;" << endl;
    X x;
    cout << "X *px = new X;" << endl;
    X *px = new X;
    cout << "X x2(x);" << endl;
    X x2(x);
    cout << "X x3 = x;" << endl;
    X x3 = x;
    cout << "vector<X> vec;" << endl;
    vector<X> vec;
    cout << "vec.push_back(x);" << endl;
    vec.push_back(x);
    cout << "nonref(x);" << endl;
    nonref(x);
    cout << "ref(x);" << endl;
    ref(x);
    cout << "delete px;" << endl;
    delete px;
    cout << "return 0;" << endl;
    return 0;
}
void nonref(X x)
{
    cout << "Pass by nonreference" << endl;
}
void ref(const X &x)
{
    cout << "Pass by reference" << endl;
}