#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string str1 = "hello";
    string str2 = "hellp";
    const char cstr1[] = "hello";
    const char cstr2[] = "hellp";
    if (str1 < str2)
        cout << "str1 < str2" << endl;
    else if (str1 == str2)
        cout << "str1 == str2" << endl;
    else
        cout << "str1 > str2";
    if (strcmp(cstr1, cstr2) > 0)
        cout << "cstr1 > cstr2" << endl;
    else if (strcmp(cstr1, cstr2) == 0)
        cout << "cstr1 == cstr2" << endl;
    else
        cout << "cstr1 < cstr2" << endl;
    return 0;
}