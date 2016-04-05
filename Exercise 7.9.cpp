#include <iostream>
#include <string>
using namespace std;
struct Person {
    std::string name;
    std::string address;
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};
istream &read(istream &is, Person &p);
ostream &print(ostream &os, const Person &p);
int main()
{
    Person p;
    read(cin, p);
    print(cout, p);
    return 0;
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