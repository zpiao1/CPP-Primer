#include <string>
#include <iostream>
class ZooAnimal;
// the order of the keywords public and virtual is not significant
class Raccoon : public virtual ZooAnimal { /* ... */ };
class Bear : virtual public ZooAnimal { /* ... */ };
class Panda : public Bear, public Raccoon, public Endangered {};
using namespace std;
void dnace(const Bear&);
void rummage(const Raccoon&);
ostream& operator<<(ostream&, const ZooAnimal&);
int main()
{
    Panda ying_yang;
    dance(ying_yang);   // ok: passes Panda object as a Bear
    rummage(ying_yang); // ok: passes Panda object as a Raccoon
    cout << ying_yang;  // ok: passes Panda object as a ZooAnimal
    return 0;
}