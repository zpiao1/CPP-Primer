#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    istream_iterator<int> int_it(cin);      // reads ints from cin
    istream_iterator<int> int_eof;          // end iterator value
    ifstream in("afile");
    istream_iterator<string> str_it(in);    // reads strings from "afile"
    return 0;
}