#include <iostream>
#include <string>
using namespace std;
struct Person {
    std::string name;
    std::string address;
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    Person() = default;
    Person(const std::string &s): name(s) { }
    Person(const std::string &s1, const std::string &s2): name(s1), address(s2) { }
    Person(istream &is);
};
istream &read(istream &is, Person &p);
ostream &print(ostream &os, const Person &p);
int main()
{
    Person p1 = Person();
    Person p2 = Person("CKY");
    Person p3 = Person("CKY", "NTU");
    Person p4 = Person(cin);
    print(cout, p1);
    print(cout, p2);
    print(cout, p3);
    print(cout, p4);
    return 0;
}
Person::Person(istream &is)
{
    read(is, *this);
}
istream &read(istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

ostream &print(ostream &os, const Person &p)
{
    os << "Name: " << p.getName() << endl
       << "Address: " << p.getAddress() << endl;
    return os;
}