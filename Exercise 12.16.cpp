#include <memory>
using namespace std;
int main()
{
    unique_ptr<int> p;
    int q = 42;
    int *pq = &q;
    p = pq;
    return 0;
}