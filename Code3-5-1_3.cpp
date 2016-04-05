#include <iostream>
using namespace std;
int main()
{
    char a1[] = {'C', '+', '+'};        // list initialization, no null
    char a2[] = {'C', '+', '+', '\0'};  // list initialization, explicit null
    char a3[] = "C++";                  // null terminator added automatically
    const char a4[6] = "Daniel";        // error: no space for the null!
}