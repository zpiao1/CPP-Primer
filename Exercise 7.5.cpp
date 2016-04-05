#include <iostream>
#include <string>
using namespace std;
struct Person {
    std::string name;
    std::string address;
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};
int main()
{
    Person p;
    cin >> p.name >> p.address;
    cout << p.getName() << endl
         << p.getAddress() << endl;
    return 0;
}
