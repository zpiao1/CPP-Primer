
#include <iostream>
using namespace std;
int main()
{
    size_t size;
    cout << "Enter the size of the array: ";
    cin >> size;
    char *cstr = new char[size + 1];
    size_t i = 0;
    char c;
    while (i != size) {
        cin >> c;
        cstr[i++] = c;
    }
    cstr[i] = '\0';
    cout << cstr << endl;
    delete[] cstr;
    return 0;
}
