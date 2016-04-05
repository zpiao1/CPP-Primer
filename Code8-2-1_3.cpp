#include <fstream>
#include <string>
using namespace std;
int main()
{
    string ifile;
    ifstream in(ifile); // construct an ifstream and open the given file
    ofstream out;       // output file stream that is not associated with any file
    out.open(ifile + ".copy");  // open the specified file
    if (out)    // check that the open succeeded
        // the open succeeded, so we can use the file
    in.close(); // close the file
    in.open(ifile + "2");   // open another file
    
    return 0;
}