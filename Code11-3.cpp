#include <map>
#include <set>
#include <string>
using namespace std;
int main()
{
    set<string>::value_type v1;     // v1 is a string
    set<string>::key_type v2;       // v2 is a string
    map<string, int>::value_type v3;    // v3 is a pair<const string, int>
    map<string, int>::key_type v4;      // v4 is a string
    map<string, int>::mapped_type v5;   // v5 is an int
    return 0;
}