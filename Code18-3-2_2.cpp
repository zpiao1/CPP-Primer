#include <string>
using namespace std;
void print(const Bear&);
void print(const Endangered&);
int main()
{
    Panda ying_yang("ying_yang");
    print(ying_yang);   // error: ambiguous
    return 0;
}