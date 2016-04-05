#include <memory>
void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *pc) {
        disconnect(*pc);
    });
}