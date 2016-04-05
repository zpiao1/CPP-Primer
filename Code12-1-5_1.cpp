#include <memory>
using namespace std;
int main()
{
    unique_ptr<double> p1;  // unique_ptr that can point at a double
    unique_ptr<int> p2(new int (42));   // p2 points to int with value 42
    return 0;
}