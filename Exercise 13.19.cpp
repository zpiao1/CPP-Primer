#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
    static int ID_generator;
    int identifier;
    string name;
public:
    Employee():
        identifier(++ID_generator) {}
    Employee(const string &s):
        identifier(++ID_generator), name(s) {}
    Employee(const Employee &e):
        identifier(++ID_generator), name(e.name) {}
    Employee &operator=(const Employee &e);
};
int Employee::ID_generator = 0;
Employee &Employee::operator=(const Employee &e)
{
    identifier = ++ID_generator;
    name = e.name;
    return *this;
}