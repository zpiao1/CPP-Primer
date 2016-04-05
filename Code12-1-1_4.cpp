#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> v1;  // empty vector
    {   // new scope
        vector<string> v2 = {"a", "an", "the"};
        v1 = v2;    // copies the elements from v2 into v1
    }   // v2 is destroyed, which destroys the elements in v2
        // v1 has three elements, which are copies of the ones originally in v2
    Blob<string> b1;    // new Blob
    {   // new scope
        Blob<string> b2 = {"a", "an", "the"};
        b1 = b2;    // b1 and b2 share the same elements
    }   // b2 is destroyed, but the elements in b2 must not be destroyed
        // b1 points to the elements originally created in b2
    return 0;
}   