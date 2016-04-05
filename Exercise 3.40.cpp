#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    const char str1[] = "Hello";
    const char str2[] = " world!";
    char str3[13];
    strcpy(str3, str1);
    strcat(str3, str2);
    cout << str3 << endl;
    return 0;
}