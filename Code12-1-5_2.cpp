#include <string>
#include <memory>
using namespace std;
int main()
{
    unique_ptr<string> p1(new string("Stegosaurus"));
    unique_ptr<string> p2(p1);  // error: no copy for unique_ptr
    unique_ptr<string> p3;
    p3 = p2;                    // error: no assign for unique_ptr
    return 0;
}