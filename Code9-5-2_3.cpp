#include <string>
using namespace std;
int main()
{
    string s("C++ Primer"), s2 = s; // initialize s and s2 to "C++ Primer"
    s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
    s2.append(" 4th Ed.");          // equivalent: appends " 4th Ed." to s2; s == s2
    // equivalent way to replace "4th" by "5th"
    s.erase(11, 3); // s == "C++ Primer Ed."
    s.insert(11, "5th");    // s == "C++ Primer 5th Ed."
    // starting at position 11, erase three characters and then insert "5th"
    s2.replace(11, 3, "5th");   // equivalent: s == s2
    s.replace(11, 3, "Fifth");  // s == "C++ Primer Fifth Ed."
    return 0;
}