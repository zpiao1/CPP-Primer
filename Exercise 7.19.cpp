#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    std::string name;
    std::string address;
public:
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    Person() = default;
    Person(const std::string &s): name(s) { }
    Person(const std::string &s1, const std::string &s2): name(s1), address(s2) { }
    Person(istream &is);
};
istream &read(istream &is, Person &p);
ostream &print(ostream &os, const Person &p);
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