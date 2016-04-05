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
};
int Employee::ID_generator = 0;