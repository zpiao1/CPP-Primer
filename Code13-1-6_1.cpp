using namespace std;
struct NoCopy {
    NoCopy() = default; // use the synthesized default constructor
    NoCopy(const NoCopy&) = delete; // no copy
    NoCopy &operator=(const NoCopy &) = delete; // no assignment
    ~NoCopy() = default;    // use the synthesized destructor
    // other elements
};