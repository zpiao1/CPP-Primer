#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;    // s3 is hello, world\n
    s1 += s2;       // equivalent to s1 = s1 + s2
    return 0;
}
