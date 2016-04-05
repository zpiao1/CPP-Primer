#include <string>
using namespace std;
int main()
{
    string river("Mississippi");
    auto first_pos = river.find("is");  // returns 1
    auto last_pos = river.rfind("is");  // returns 4
    return 0;
}