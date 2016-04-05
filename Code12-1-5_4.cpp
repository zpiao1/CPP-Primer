#include <memory>
unique_ptr<int> clone(int p) {
    // ok: explicitly create a unique_ptr<int> from int *
    return unique_ptr<int>(new int(p));
}
unique_ptr<int> clone(int p) {
    unique_ptr<int> ret(new int(p));
    // . . .
    return ret;
}