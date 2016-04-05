#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;
int main()
{
    ifstream words("words.txt");
    istream_iterator<string> in_iter(words), eof;
    ostream_iterator<string> out_iter(cout, " ");
    vector<string> svec(in_iter, eof);
    for (const auto &s : svec)
        *out_iter++ = s;
    cout << endl;
    return 0;
}