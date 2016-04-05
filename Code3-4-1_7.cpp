#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> text;
    // print each line in text up to the first blank line
    for (auto it = text.cbegin();
         it != text.cend() && !it->empty(); ++it)
        cout << *it << endl;
    return 0;
}
