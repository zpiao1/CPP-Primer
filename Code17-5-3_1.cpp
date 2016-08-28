#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
    // set the marker to a fixed position
    seekg(new_position);    // set the read marker to the given pos_type location
    seekp(new_position);    // set the write marker to the given pos_type location

    // offset some distance ahead of or behind the given starting point
    seekg(offset, from);    // set the read marker offset distance from from
    seekp(offset, from);    // offset has type off_type
    return 0;
}