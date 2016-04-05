#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    // count occurrences, but the words won't be in alphabetical order
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word]; // fetch and increment the counter for word
    for (const auto &w : word_count)    // for each element in the map
        // print the results
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    return 0;
}