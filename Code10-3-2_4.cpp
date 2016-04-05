#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string& make_plural(string::size_type count, string &s, const string &suffix);
void biggies(vector<string> &words, vector<string>::size_type);
int main()
{
    return 0;
}
void biggies(vector<string> &words, vector<string>::size_type)
{
    // get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(),
        [sz](const string &a)
            { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    // print words of the given size of longer, each one followed by a space
    for_each(wc, words.end(),
        [](const string &s){ cout << s << ' '; });
    cout << endl;
}