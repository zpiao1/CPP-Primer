#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    istream_iterator<int> in_iter(cin); // read ints from cin
    istream_iterator<int> eof;          // istream "end" iterator
    while (in_iter != eof)  // while there's valid input to read
        // postfix increment reads the stream and retunrns the old value of the iterator
        // we dereference that iterator to get the previous value read from the stream
        vec.push_back(*in_iter++);
    istream_iterator<int> in_iter(cin), eof;    // read ints from cin
    vector<int> vec(in_iter, eof);  // construct vec from an iterator range
    return 0;
}