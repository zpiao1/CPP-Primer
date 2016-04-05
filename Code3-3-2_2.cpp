#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // read words from the standard input and store them as elements in a vector
    string word;
    vector<string> text;    // empty vector
    while (cin >> word) {
        text.push_back(word);   // append word to text
    }
    return 0;
}
