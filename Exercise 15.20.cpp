#include <iostream>
using namespace std;
class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};
struct Pub_Derv: public Base {
    // |-----------------------------------------------------------------------------|
    // |                                  |    Accessible       |    Inaccessible    |
    // |-----------------------------------------------------------------------------|
    // |     This class                   | pub_mem(), prot_mem |      priv_mem      |
    // |-----------------------------------------------------------------------------|
    // | Users of this class              |     pub_mem()       | prot_mem, priv_mem |
    // |-----------------------------------------------------------------------------|
    // | (Public) Derived class from this | pub_mem(), prot_mem |      priv_mem      |
    // |-----------------------------------------------------------------------------|
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv: private Base {
    // |-----------------------------------------------------------------------------|
    // |                                  |    Accessible       |      Inaccessible  |
    // |-----------------------------------------------------------------------------|
    // |     This class                   | pub_mem(), prot_mem | priv_mem           |
    // |-----------------------------------------------------------------------------|
    // | Users of this class              | None                | All                |
    // |-----------------------------------------------------------------------------|
    // | (Public) Derived class from this | None                | All                |
    // |-----------------------------------------------------------------------------|
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv: protected Base {
    // |-----------------------------------------------------------------------------|
    // |                                  |    Accessible       |      Inaccessible  |
    // |-----------------------------------------------------------------------------|
    // |     This class                   | pub_mem(), prot_mem | priv_mem           |
    // |-----------------------------------------------------------------------------|
    // | Users of this class              | None                | All                |
    // |-----------------------------------------------------------------------------|
    // | (Public) Derived class from this | pub_mem(), prot_mem | priv_mem           |
    // |-----------------------------------------------------------------------------|
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public: public Pub_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private: public Priv_Derv {
    void memfcn(Base &b) { b = *this; } // Base is inaccessible
};
struct Derived_from_Protected: public Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};
int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;
    Base *p = &d1;
    p = &d2;    // Base is an inaccessible base of Priv_Derv
    p = &d3;    // Base is an inaccessible base of Prot_Derv
    p = &dd1;
    p = &dd2;   // Base is an inaccessible base of Derived_from_Private
    p = &dd3;   // Base is an inaccessible base of Derived_from_Protected
    return 0;
}