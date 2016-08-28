#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
struct Base {
    virtual ~Base() = default;
};
struct Derived: public Base {};
struct Sales_data {};
int main()
{
    int arr[10];
    Derived d;
    Base *p = &d;
    cout << typeid(42).name() << ", "
         << typeid(arr).name() << ", "
         << typeid(Sales_data).name() << ", "
         << typeid(std::string).name() << ", "
         << typeid(p).name() << ", "
         << typeid(*p).name() << endl;
    return 0;
}