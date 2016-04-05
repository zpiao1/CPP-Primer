#include <list>
#include <string>
#include <vector>
#include <deque>
#include <forward_list>
using namespace std;
int main()
{
    // each container has three elements, initialized from the given initializers
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
    list<string> list2(authors);    // ok: types match
    deque<string> authList(authors);    // error: container types don't match
    vector<string> words(articles);     // error: element types must match
    // ok: converts const char* elements to string
    forward_list<string> words(articles.begin(), articles.end());
    // copies up to but not including the element denoted by it
    deque<string> authList(authors.begin(), it);
    vector<int> ivec(10, -1);       // ten int elements, each initialized to -1
    list<string> svec(10, "hi!");   // ten strings; each element is "hi!"
    forward_list<int> ivec(10);     // ten elements, each initialized to 0
    deque<string> svec(10);         // ten elements, each an empty string
    return 0;
}