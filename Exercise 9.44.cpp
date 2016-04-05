#include <iostream>
#include <string>
using namespace std;
void replaceOldWithNew(string &s, const string &oldVal, const string &newVal);
int main()
{
    string s("You can try thru this, tho there are other ways.");
    replaceOldWithNew(s, "tho", "though");
    replaceOldWithNew(s, "thru", "through");
    cout << s << endl;
    return 0;
}
void replaceOldWithNew(string &s, const string &oldVal, const string &newVal)
{
    decltype(s.size()) index = 0;
    while (index != s.size()) {
        auto subIndex = index;
        decltype(oldVal.size()) oldIndex = 0;
        while (oldIndex != oldVal.size()) {
            if (s[subIndex] != oldVal[oldIndex])
                break;
            ++subIndex;
            ++oldIndex;
        }
        if (oldIndex == oldVal.size()) {
            s.replace(index, oldVal.size(), newVal);
            index += newVal.size();
        } else
            ++index; 
    }
}