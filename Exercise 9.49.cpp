#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream ifs("words.txt");
    string longest;
    string word;
    string ascenders("bdfhijkltABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    string descenders("gjpqy");
    while (ifs >> word) {
        if (word.find_first_of(ascenders) == string::npos &&
            word.find_first_of(descenders) == string::npos &&
            word.size() > longest.size())
            longest = word;
    }
    cout << longest << endl;
    return 0;
}