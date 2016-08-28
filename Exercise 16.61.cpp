#include <memory>
#include <functional>
using namespace std;

template <class T, typename... Args>
shared_ptr<T> makeShared(Args&&... args)
{
    // call the constructor of T, forwarding the arguments
    return shared_ptr<T>(new T(std::forward(args)...));
}