#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        if (isupper(word[0]))
            word[0] = tolower(word[0]);
        if (!isalpha(word[word.size() - 1]))
            word.erase(word.size() - 1);
        ++word_count[word];
    }
    for (const auto &p : word_count)
        cout << p.first << ": " << p.second << (p.second == 1 ? " time" : " times") << endl;
    return 0;
}