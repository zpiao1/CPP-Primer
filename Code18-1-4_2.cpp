#include <stdexcept>
#include <exception>
using namespace std;
// this function will compile, even though it clearly violates its exception specification
void f() noexcept   // promises not to throw any exception
{
    throw exception();  // violates the exception specification
}