#include <memory>
using namespace std;
struct destination; // represents what we are connecting to
struct connection;  // information needed to use the connection
connection connect(destination *);  // open the connection
void disconnect(connection);        // close the given connection
void f(destination &d /* other parameters */)
{
    // get a connection; must remember to close it when done
    connection c = connect(&d);
    // use the connection
    // if we forgot to call disconnect before exiting f, there will be no way to close c
}
void end_connection(connection *p)
{
    disconnect(*p);
}
void f(destination &d /* other parameters */)
{
    connection c = connect(&d);
    shared_ptr<connection> (&c, end_connection);
    // use the connection
    // when f exits, even if by an exception, the connection will be properly closed
}