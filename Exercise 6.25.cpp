#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
    string str;
    str = argv[1] + str + argv[2];
    cout << str << endl;
    return 0;
}