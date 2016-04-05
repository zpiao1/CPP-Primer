#include <memory>
using namespace std;
int main()
{
    shared_ptr<double> p1;  // shared_ptr that can point at a double
    shared_ptr<int> p2(new int(42));    // p2 points to an int with value 42
    return 0;
}