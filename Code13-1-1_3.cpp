#include <string>
using namespace std;
int main()
{
    string dots(10, '.');               // direct initialization
    string s(dots);                     // direct initialization
    string s2 = dots;                   // copy initialization
    string null_book = "9-999-99999-9"; // copy initialization
    string nines = string(100, '9');    // copy initialization
    return 0;
}