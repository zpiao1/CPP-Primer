#include <string>
using namespace std;
int main()
{
    s.insert(s.size(), 5, '!'); // insert five exclamation points at the end of s
    s.erase(s.size() - 5, 5);   // erase the last five characters from s
    const char *cp = "Stately, plump Buck";
    s.assign(cp, 7);            // s == "Stately"
    s.insert(s.size(), cp + 7); // s == "Stately, plump Buck"
    return 0;
}