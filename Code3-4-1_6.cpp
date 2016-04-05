#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> words;
    auto it = words.cbegin();
    (*it).empty()   // dereferences it and calls the member empty on the resulting object
    *it.empty()     // error: attempts to fetch the member named empty from it
                    //        but it is an iterator and has no member named empty
    return 0;
}
