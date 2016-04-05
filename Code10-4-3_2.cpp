#include <iostream>
#include <string>
using namespace std;
int main()
{
    // find the first element in a comma-separated list
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;
    // find the last element in a comma-separated list
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    // WRONG: will generate the word in reverse order
    cout << string(line.crbegin(), comma) << endl;
    // ok: get a forward iterator and read to the end of line
    cout << string(rcomma.base(), line.cend()) << endl;
    return 0;
}