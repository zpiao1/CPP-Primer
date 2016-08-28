#include <iostream>
using namespace std;
int main()
{
    char str[10];
    while (cin.getline(str, 10))
        cout << str << endl;
    return 0;
}