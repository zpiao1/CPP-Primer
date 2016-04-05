#include <utility>
#include <string>
#include <vector>
using namespace std;
int main()
{
    pair<string, string> anon;  // holds two strings
    pair<string, size_t> word_count;    // holds a string and an size_t
    pair<string, vector<int>> line; // holds strng and vector<int>
    pair<string, string> author{"James", "Joyce"};
    return 0;
}