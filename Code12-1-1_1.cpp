#include <list>
#include <memory>
#include <string>
#include <list>
using namespace std;
int main()
{
    shared_ptr<string> p1;  // shared_ptr that can point at a string
    shared_ptr<list<int>> p2;   // shared_ptr that can point at a list of ints
    // if p1 is not null, check whether it's emtpy string
    if (p1 && p1->empty())
        *p1 = "hi"; // if so dereference p1 to assign a new value to that string
    // shard_ptr that points to an int with value 42
    shared_ptr<int> p3 = make_shared<int>(42);
    // p4 points to a string with value 9999999999
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    // p5 points to an int that is value initialized (§ 3.3.1 (p. 98)) to 0
    shard_ptr<int> p5 = make_shared<int>();
    // p6 points to a dynamically allocated, emtpy vector<string>
    auto p6 = make_shared<vector<string>>();
    return 0;
}