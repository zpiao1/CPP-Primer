#include <string>
using namespace std;
void pluralize(size_t cnt, string &word)
{
    if (cnt > 1)
        word.push_back('s');    // same as word += 's'
}