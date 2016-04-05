#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    // for each file passed to the program
    for (auto p = argv + 1; p != argv + argc; ++p) {
        ifstream input(*p); // create input and open the file
        if (input) {        // if the file is ok, "process" this file
            process(input);
        } else
            cerr << "couldn't open: " + string(*p);
    }   // input goes out of scope and is destroyed on each iteration
    return 0;
}