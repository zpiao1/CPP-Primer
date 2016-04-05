#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    ifstream in("nums.txt");
    ofstream odd_out("odds.txt");
    ofstream even_out("evens.txt");
    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> odd_iter(odd_out, " "), even_iter(even_out, "\n");
    while (in_iter != eof) {
        int i = *in_iter++;
        if (i % 2 == 0)
            *even_iter++ = i;
        else
            *odd_iter++ = i;
    }
    return 0;
}