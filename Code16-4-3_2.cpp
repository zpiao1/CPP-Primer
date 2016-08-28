#include <functional>
using namespace std;
// fun has zero or more parameters each of which is
// an rvalue reference to a template parameter type
template <typename... Args>
void fun(Args&&... args)    // expands Args as a list of rvalue references
{
    // the argument to work expands both Args and args
    work(std::forward<Args>(args)...);
}