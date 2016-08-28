#include <iostream>
using namespace std;
int main()
{
    char word[80];
    while (cin.getline(word, 80, ' '))
        cout << word << endl;
    return 0;
}