#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::cin >> s;
    // equivalent to
    // opeartor>>(std::cin, s);
    using std::operator>>;  // needed to allow cin >> s
    std::operator>>(std::cin, s);   // ok: explicitly use std::>>
    return 0;
}