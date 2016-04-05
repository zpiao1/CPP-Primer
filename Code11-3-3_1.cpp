#include <iostream>
#include <map>
using namespace std;
int main()
{
    // erase on a key returns the number of elements removed
    if (word_count.erase(removal_word))
        cout << "ok: " << removal_word << " removed\n";
    else
        cout << "oops: " << removal_word << " not found!\n";
    auto cnt = authors.erase("Barth, John");
    return 0;
}