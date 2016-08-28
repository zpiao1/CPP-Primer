#include <string>
using namespace std;
int main()
{
    string *sp = new string("a value"); // allocate an initialize a string
    sp->~string();
    return 0;
}