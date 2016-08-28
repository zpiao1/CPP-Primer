#include <string>
using namespace std;
class ZooAnimal;
class Bear;
class Endangered;
class Panda;
int main()
{
    Bear *pb = new Panda("ying_yang");
    pb->print();        // ok: Panda::print()
    pb->cuddle();       // error: not part of the Bear interface
    pb->highlight();    // error: not part of the Bear interface
    delete pb;          // ok: Panda::~Panda()
    Endangered *pe = new Panda("ying_yang");
    pe->print();        // ok: Panda::print()
    pe->toes();         // error: not part of the Endangered interface
    pe->cuddle();       // error: not part of the Endangered interface
    pe->highlight();    // ok: Panda::highlight()
    delete pe;          // ok: Panda::~Panda()
    return 0;
}