#include <string>
using namespace std;
int main()
{
    string s1 = "a value", s2 = "another";
    auto n = (s1 + s2).find('a');
    s1 + s2 = "wow!";
    return 0;
}