#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    // remember the current write position in mark
    ostringstream writeStr; // output stringstream
    ostringstream::pos_type mark = writeStr.tellp();
    // ...
    if (cancelEntry)
        // return to the remembered position
        writeStr.seekp(mark);
    return 0;
}