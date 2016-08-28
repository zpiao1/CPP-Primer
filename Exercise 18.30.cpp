#include <iostream>
using namespace std;
class Class {
public:
    Class() { cout << "Class::Class()" << endl; }
    virtual ~Class() { cout << "Class::~Class()" << endl; }
};

class Base : public Class {
public:
    Base() { cout << "Base::Base()" << endl; }
    Base(int) { cout << "Base::Base(int)" << endl; }
    Base(const Base&) { cout << "Base::Base(const Base&)" << endl; }
    ~Base() { cout << "Base::~Base()" << endl; }
};

class D1 : virtual public Base {
public:
    D1() { cout << "D1::D1()" << endl; }
    D1(int i): Base(i) { cout << "D1::D1(int)" << endl; }
    D1(const D1& d1): Base(d1) { cout << "D1::D1(const D1&)" << endl; }
    ~D1() { cout << "D1::~D1()" << endl; }
};

class D2 : virtual public Base {
public:
    D2() { cout << "D2::D2()" << endl; }
    D2(int i): Base(i) { cout << "D2::D2(int)" << endl; }
    D2(const D2& d2): Base(d2) { cout << "D2::D2(const D2&)" << endl; }
    ~D2() { cout << "D2::~D2()" << endl; }
};

class MI : public D1, public D2 {
public:
    MI() { cout << "MI::MI()" << endl; }
    MI(int i): Base(i), D1(i), D2(i) { cout << "MI::MI(int)" << endl; }
    MI(const MI& mi): Base(mi), D1(mi), D2(mi) 
    { cout << "MI::MI(const MI&)" << endl; } 
    ~MI() { cout << "MI::~MI()" << endl; }
};

class Final : public MI, public Class {
public:
    Final() { cout << "Final::Final()" << endl; }
    Final(int i): Base(i), MI(i) { cout << "Final::Final(int)" << endl; }
    Final(const Final& final): Base(final), MI(final) { cout << "Final::Final(const Final&)" << endl; }
    ~Final() { cout << "Final::~Final()" << endl; }
};

int main()
{
    Final *pf1 = new Final;
    cout << endl;
    delete pf1;
    cout << endl;
    Final *pf2 = new Final(42);
    cout << endl;
    Final *pf3 = new Final(*pf2);
    cout << endl;
    delete pf2;
    cout << endl;
    delete pf3;
    cout << endl;
    return 0;
}

