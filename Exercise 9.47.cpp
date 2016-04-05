#include <string>
#include <iostream>
using namespace std;
int main()
{
    string alphanumeric("ab2c3d7R4E6");
    string num("0123456789");
    string letters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string::size_type pos = 0;
    while ((pos = alphanumeric.find_first_of(num, pos)) != string::npos) {
        cout << alphanumeric[pos];
        pos++;
    }
    cout << endl;
    pos = 0;
    while ((pos = alphanumeric.find_first_of(letters, pos)) != string::npos) {
        cout << alphanumeric[pos];
        pos++;
    }
    cout << endl;
    pos = 0;
    while ((pos = alphanumeric.find_first_not_of(letters, pos)) != string::npos) {
        cout << alphanumeric[pos];
        pos++;
    }
    cout << endl;
    pos = 0;
    while ((pos = alphanumeric.find_first_not_of(num, pos)) != string::npos) {
        cout << alphanumeric[pos];
        pos++;
    }
    cout << endl;
    return 0;
}