#include <string>
#include <vector>
#include <list>
using namespace std;
int main()
{
    vector<string> svec;
    list<string> slist;
    // equivalent to calling slist.push_front("Hello!");
    slist.insert(slist.begin(), "Hello!");
    // no push_front on vector but we can insert before begin()
    // warning: inserting anywhere but at the end of a vector might be slow
    svec.insert(svec.begin(), "Hello!");
    svec.insert(svec.end(), 10, "Anna");
    vector<string> v = {"quasi", "simba", "frollo", "will"};
    // insert the last two elements of v at the beginning of slist
    slist.insert(slist.begin(), v.end() - 2, v.end());
    slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
    // run-time error: iterators denoting the range to copy from
    // must not refer to the same container as the one we are changing
    slist.insert(slist.begin(), slist.begin(), slist.end());
    return 0;
}