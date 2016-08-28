#include "Blob.h"
#include <iterator>
#include <vector>
#include <list>
using namespace std;
int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    list<const char*> w = {"now", "is", "the", "time"};
    // instantiates the Blob<int> class
    // and the Blob<int> constructor that has two int* parameters
    Blob<int> a1(begin(ia), end(ia));
    // instantiates the Blob<int> constructor that has
    // two vector<long>::iterator parameters
    Blob<int> a2(vi.begin(), vi.end());
    // instantiates the Blob<string> class and the Blob<string>
    // constructor that has two list<const char*>::iterator parameters
    Blob<string> a3(w.begin(), w.end());
    return 0;
}
// Definition of a1 instantiates
// Blob<int>::Blob(int*, int*);