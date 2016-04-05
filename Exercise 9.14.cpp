#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
int main()
{
    list<const char*> cStrList= {"Hello!", "Thank you!", "Thank you very much!"};
    vector<string> strVec;
    strVec.assign(cStrList.cbegin(), cStrList.cend());
    for (const auto &s : strVec)
        cout << s << endl;
    return 0;
}