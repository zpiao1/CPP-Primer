#include <fstream>
#include <string>
using namespace std;
int main()
{
    // file1 is truncated in each of these cases
    ofstream out("file1");  // out and trunc are implicit
    ofstream out2("file1", ofstream::out);  // trunc is implicit
    ofstream out3("file1", ofstream::out | ofstream::trunc);

    // to preserve the file's contents, we must explicitly specify app mode
    ofstream app("file2", ofstream::app);   // out is implicit
    ofstream app2("file2", ofstream::out | ofstream::app);
    return 0;
}