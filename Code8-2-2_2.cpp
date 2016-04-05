#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream out;   // no file mode is set
    out.open("scratchpad"); // mode implicitly out and trunc
    out.close();    // close out so we can use it for a differnt file
    out.open("precious", ofstream::app);    // mode is out and app
    out.close();
    return 0;
}