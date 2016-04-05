#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void biggies(vector<string> &words, vector<string>::size_type sz);
void elimDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);
int main()
{
    return 0;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);    // put words in alphabetical order and remove duplicates
    // resort by length, maintaining alphabetical order among words of the same length
    stable_sort(words.begin(), words.end(), isShorter);
    // get an iterator to the first element whose size() is >= sz
    // compute the number of elements with size >= sz
    // print words of the given size or longer, each one followed by a space
}