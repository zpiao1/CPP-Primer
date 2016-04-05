#include <map>
#include <string>
#include <set>
#include <iostream>
using namespace std;
int main()
{
    // cound the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string size_t
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
        // count only words that are not in exclude
        if (exclude.find(word) == exclude.end())
            ++word_count[word];     // fetch and increment the counter for word
    return 0;
}