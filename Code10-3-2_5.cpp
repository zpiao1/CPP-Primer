#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);    // put words in alphabetical order and remove duplicates
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(), 
        [](const string &a, const string &b)
          { return a.size() > b.size(); });
    // get an iterator to the first element whose size() is >= sz
    auto cw = find_if(words.begin(), words.end(),
        [sz](const string &a)
            { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = words.end() - cw;
    cout << count << ' ' << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    // print words of each given size or longer, each one followed by a space
    for_each(words.begin(), words.end(),
        [](const string &a)
          { cout << a << ' '; });
    cout << endl;
}