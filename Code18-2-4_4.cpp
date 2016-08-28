namespace AW {
    int print(int);
}
namespace Primer {
    double print(double);
}
// using directives create an overload set of functions from different namespaces
using namespace AW;
using namespace Primer;
long double print(long double);
int main() {
    print(1);   // calls AW::print(int)
    print(3.1); // calls Primer::print(double)
    return 0;
}