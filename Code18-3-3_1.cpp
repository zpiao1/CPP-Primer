#include <string>
#include <algorithm>

class ZooAnimal;
class Bear;
class Endangered;
class Panda;
double Panda::max_weight() const
{
    return std::max(ZooAnimal::max_weight(), Endangered::max_weight());
}
using namespace std;
int main()
{
    Panda ying_yang("ying_yang");
    double d = ying_yang.max_weight();  
    return 0;
}