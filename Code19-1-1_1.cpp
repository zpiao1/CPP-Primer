#include <string>
using namespace std;
int main()
{
    // new expressions
    string *sp = new string("a value"); // allocate and initialized a string
    string *arr = new string[10];   // allocate ten default initialized strings
    delete sp;  // destroy *sp and free the memory to which sp points
    delete [] arr;  // destroy the elements in the array and free the memory
    return 0;
}