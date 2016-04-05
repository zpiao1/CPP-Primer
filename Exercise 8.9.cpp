#include <iostream>
#include <sstream>
using namespace std;
istream &process(istream &is);
int main()
{
    istringstream iss("Hello world!\n");
    process(iss);
    return 0;
}
istream &process(istream &is)
{
    char ch;
    is >> ch;
    while (!is.eof()) {
        cout << ch;
        is >> ch;
    }
    is.clear();
    return is;
}