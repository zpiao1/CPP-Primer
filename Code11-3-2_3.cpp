#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    // more verbose way to count number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word) {
        // inserts an element with key equal to word and value 1;
        // if word is already in word_count, insert does nothing
        auto ret = word_count.insert({word, 1});
        pair<map<string, size_t>::iterator, bool> ret = word_count.insert(make_pair(word, 1));
        if (!ret.second)    // word already in word_count
            ++ret.first->second;    // increment the counter
    }
    return 0;
}