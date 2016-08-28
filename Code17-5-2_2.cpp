#include <iostream>
using namespace std;
int main()
{
    int ch; // use an int, not char to hold the return from get()
    // loop to read and write all the data in the input
    while ((ch = cin.get()) != EOF)
        cout.put(ch);
    return 0;
}