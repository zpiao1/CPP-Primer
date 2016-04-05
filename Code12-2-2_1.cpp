#include <string>
using namespace std;
int main()
{
    string *const p = new string[n];    // construct n empty strings
    string s;
    string *q = p;  // q points to the first string
    while (cin >> s && q != p + n)
        *q++ = s;       // assign a new value to *q
    const size_t size = q - p;  // remember how many strings we read
    // use the array
    delete[] p; // p points to an array; must remember to use delete[]
}