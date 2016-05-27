using namespace std;
struct Base {
    int memfcn();
};
struct Derived : Base {
    int memfcn(int);    // hides memfcn in the base
};
int main()
{
    Derived d; Base b;
    b.memfcn();         // calls Base::memfcn
    d.memfcn(10);       // calls Derived::memfcn
    d.memfcn();         // error: memfcn with no arguments is hidden
    d.Base::memfcn();   // ok calls Base::memfcn
    return 0;
}