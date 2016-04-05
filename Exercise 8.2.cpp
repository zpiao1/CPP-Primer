#include <iostream>
using namespace std;
istream &process(istream &is);
int main()
{
    process(cin);
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