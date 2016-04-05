#include <string>
using namespace std;
int main()
{
    string s("hello world");
    string s2 = s.substr(0, 5);     // s2 = hello
    string s3 = s.substr(6);        // s3 = world
    string s4 = s.substr(6, 11);    // s3 = world
    string s5 = s.substr(12);       // throws an out_of_range exception
    return 0;
}