#include <list>
#include <string>
using namespace std;
int main()
{
    list<string> a = {"Million", "Shakespeare", "Austen"};
    auto it1 = a.begin();   // list<string>::iterator
    auto it2 = a.rbegin();  // list<string>::reverse_iterator
    auto it3 = a.cbegin();  // list<string>::const_iterator
    auto it4 = a.crbegin(); // list<string>::const_reverse_iterator
    // type is explicitly specified
    list<string>::iterator it5 = a.begin();
    list<string>:::const_iterator it6 = a.begin();
    // iterator or const_iterator depending on a's type of a
    auto it7 = a.begin();   // const_iterator only if a is const
    auto it8 = a.cbegin();  // it8 is const_iterator
    return 0;
}