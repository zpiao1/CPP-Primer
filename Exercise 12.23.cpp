#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    char str1[] = "Hello ", str2[] = "World!";
    string str3 = "Hello ", str4 = "World!";
    size_t len = strlen(str1) + strlen(str2);
    char *catliteral = new char[len + 1];
    size_t index = 0;
    for (size_t i1 = 0; str1[i1]; ++i1, ++index)
        catliteral[index] = str1[i1];
    for (size_t i2 = 0; str2[i2]; ++i2, ++index)
        catliteral[index] = str2[i2];
    catliteral[index] = '\0';
    string catstring(str3 + str4);
    cout << catliteral << endl;
    cout << catstring << endl;
    delete[] catliteral;
    return 0;
}