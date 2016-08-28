#include <string>
#include <iostream>
using namespace std;
// operations that take references to base classes of type Panda
void print(const Bear&);
void highlight(const Endangered&);
ostream& operator<<(ostream&, const ZooAnimal&);
int main()
{
    Panda ying_yang("ying_yang");

    print(ying_yang);   // passes Panda to a reference to Bear
    highlight(ying_yang);   // passes Panda to a reference to Endangered
    cout << ying_yang << endl;  // passes Panda to a refernce to ZooAnimal
    return 0;
}