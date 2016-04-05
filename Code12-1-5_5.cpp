#include <memory>
int main()
{
    // p points to an object of type objT and uses an object of type delT to free that object
    // it will call an object name fcn of type delT
    unique_ptr<objT, delT> p (new objT, fcn);
    return 0;
}
void f(destination &d /* other needed parameters */)
{
    connection c = connect(&d); // open the connection
    // when p is destroyed, the connection will be closed
    unique_ptr<connection, decltype(end_connection) *> p(&c, end_connection);
    // use the connection
    // when f exits, even if by an exception, the connection will be properly closed
}