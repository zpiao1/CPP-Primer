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
    ~Base() { cout << "Base::~Base()" << endl; }
};
class D1 : virtual public Base {
public:
    D1() { cout << "D1::D1()" << endl; }
    ~D1() { cout << "D1::~D1()" << endl; }
};
class D2 : virtual public Base {
public:
    D2() { cout << "D2::D2()" << endl; }
    ~D2() { cout << "D2::~D2()" << endl; }
};
class MI: public D1, public D2 {
public:
    MI() { cout << "MI::MI()" << endl; }
    ~MI() { cout << "MI::~MI()" << endl; }
};
class Final: public MI, public Class {  // Direct base 'Class' inaccessible
// Ambiguity
public:
    Final() { cout << "Final::Final()" << endl; }
    ~Final() { cout << "Final::~Final()" << endl; }
};

int main()
{
    Final f;
    cout << endl;
    Base *pb = new Class;   // Compile error: base to derived conversion
    cout << endl;
    Class *pc = new Final;  // Ambiguity: Final contains two Classes
    cout << endl;
    MI *pmi = pb;   // Compile error: base to derived conversion
    D2 *pd2 = pmi;  // OK: Derived to base with no ambiguity
    delete pb;
    cout << endl;
    delete pc;
    cout << endl;
    return 0;
}