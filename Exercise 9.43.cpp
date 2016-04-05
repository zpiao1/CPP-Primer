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
    auto iter = s.begin();
    while (iter != s.end()) {
        auto subIter = iter;
        auto oldIter = oldVal.begin();
        while (oldIter != oldVal.end()) {
            if (*subIter != *oldIter)
                break;
            ++subIter;
            ++oldIter;
        }
        if (oldIter == oldVal.end()) {
            iter = s.erase(iter, subIter);
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += oldVal.size();
        } else
            ++iter;
    }
}