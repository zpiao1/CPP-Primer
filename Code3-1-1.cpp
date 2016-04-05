#include <iostream>
// using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
int main()
{
    int i;
    cin >> i;           // ok: cin is a synonym for std::cin
//    cout << i;          // error: no using declaration; we must use the full name
    // error: 'cout' was not declared in this scope
    std:: cout << i;    // ok: explicitly use cout from namespace std
    return 0;
}
