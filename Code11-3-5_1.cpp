#include <set>
using namespace std;
int main()
{
    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    iset.find(1);       // returns an iterator that refers to the element with key == 1
    iset.find(11);      // returns the iterator == iset.end();
    iset.count(1);      // returns 1
    iset.count(0);      // returns 0
    return 0;
}