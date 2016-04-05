#include <string>
#include <utility>

// the compiler will synthesize the move operations for X and hasX
struct X {
    int i;  // built-in types can be moved
    std::string s;  // string defines its own move operations
};
struct hasX {
    X mem;  // X has synthesized move operations
};
X x, x2 = std::move(x); // uses the synthesized move constructor
hasX hx, hx2 = std::move(hx);   // uses the synthesized move constructor
// assume Y is a class that defines its own copy constructor but not a move constructor
struct Y {
    hasY() = default;
    hasY(hasY&&) = default;
    Y mem;  // hasY will have a deleted move constructor
};
hasY hy, hy2 = std::move(hy);   // error: move constructor is deleted