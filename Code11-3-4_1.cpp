#include <map>
#include <string>
using namespace std;
int main()
{
    map <string, size_t> word_count;    // empty map
    // insert a value-initialized element with key Anna; then assign 1 to its value
    word_count["Anna"] = 1;
    cout << word_count["Anna"]; // fetch the element indexed by Anna; prints 1
    ++word_count["Anna"];       // fetch the element and add 1 to it
    cout << word_count["Anna"]; // fetch the element and print it; prints 2
    return 0;
}