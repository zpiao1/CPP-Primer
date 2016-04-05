#include <memory>
using namespace std;
int main()
{
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);    // wp weakly shares with p; use count in p is unchanged
    if (shared_ptr<int> np = wp.lock()) {   // true if np is not null
        // inside the if, np shares its object with p
    }
    return 0;
}