#include <iostream>
using namespace std;
int main()
{
    char ch;    // using a char here invites disaster!
    // the return from cin.get is converted to char and then compared to an int
    while ((ch = cin.get()) != EOF)
        cout.put(ch);
    return 0;
}