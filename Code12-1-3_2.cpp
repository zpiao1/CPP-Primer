#include <memory>
using namespace std;
shared_ptr<int> clone(int p) {
    return new int(p);  // error: implicit conversion to shared_ptr<int>
}
shared_ptr<int> clone(int p) {
    // ok: explicitly create a shared_ptr<int> from int*
    return shared_ptr<int>(new int(p));
}
int main()
{
    shared_ptr<int> p1 = new int(1024); // error: must use direct initialization
    shared_ptr<int> p2(new int(1024));  // ok: uses direct initialization
    return 0;
}