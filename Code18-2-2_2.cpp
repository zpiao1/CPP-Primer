#include <iostream>
using namespace std;
// namespace A and function f are defined at global scope
namespace A {
    int i, j;
}
void f()
{
    using namespace A;  // injects the names from A into the global scope
    cout << i * j << endl;  // uses i and j from namespace A
    // ...
}