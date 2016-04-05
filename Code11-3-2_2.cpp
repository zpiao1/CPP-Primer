#include <map>
#include <string>
using namespace std;
int main()
{
    // four ways to add word to word_count
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
    return 0;
}