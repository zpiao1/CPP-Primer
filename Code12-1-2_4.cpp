#include <string>
using namespace std;
int main()
{
    string *ps1 = new string;   // default initialized to empty string
    string *ps = new string();  // value initialized to emtpy string
    int *pi1 = new int;         // default initialized; *pi1 is undefined
    int *pi2 = new int();       // value initialized to 0; *pi2 is 0
    auto p1 = new auto(obj);    // p points to an object of the type of obj
                                // that object is initialized from obj
    auto p2 = new auto{a,b,c};  // error: must use parentheses for the initializer
    // allocate and initialize a const int
    const int *pci = new const int(1024);
    // allocate a default-initialized const empty string
    const string *pcs = new const string;
    return 0;
}