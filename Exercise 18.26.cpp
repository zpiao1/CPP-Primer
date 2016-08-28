#include <iostream>
#include <vector>
#include <string>
struct Base1 {
    void print(int) const;  // public by default
protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};
struct Base2 {
    void print(double) const;   // public by default
protected:
    double fval;
private:
    double dval;
};
struct Derived : public Base1 {
    void print(std::string) const;  // public by default
protected:
    std::string sval;
    double dval;
};
struct MI : public Derived, public Base2 {
    using Base1::print;
    void print(std::vector<double>);    // public by default
    void foo(double);
protected:
    int *ival;
    std::vector<double> dvec;
};

int ival;
double dval;

void MI::foo(double cval)
{
    int dval;
    // exercise questions occur here
    dval = Base1::dval + Derived::dval;
    fval = dvec.back();
    sval[0] = Base1::cval;
}

void Base1::print(int i) const
{
    std::cout << "void Base1::print(int) const" << std::endl;
    std::cout << i << std::endl;
}

void Base2::print(double d) const
{
    std::cout << "void Base2::print(double) const" << std::endl;
    std::cout << d << std::endl;
}

void Derived::print(std::string s) const
{
    std::cout << "void Derived::print(std::string) const" << std::endl;
    std::cout << s << std::endl;
}

void MI::print(std::vector<double> v)
{
    std::cout << "void MI::print(std::vector<double>" << std::endl;
    for (double d : v)
        std::cout << d << ' ';
    std::cout << std::endl;
}

using namespace std;
int main()
{
    MI mi;
    mi.print(42);   // MI::print hides the functions from base classes of it
    return 0;
}