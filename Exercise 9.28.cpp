#include <forward_list>
#include <string>
#include <iostream>
using namespace std;
void insertAfter(forward_list<string> &flst, const string &s1, const string &s2);
int main()
{
    forward_list<string> flst = {"This", "is", "a", "sentence"};
    string str1 = "nonexist";
    string str2 = ".";
    insertAfter(flst, str1, str2);
    for (const auto &s : flst)
        cout << s << ' ';
    cout << endl;
    return 0;
}
void insertAfter(forward_list<string> &flst, const string &s1, const string &s2)
{
    auto curr = flst.begin();
    auto mark = curr;
    while (++mark != flst.end()) {
        if (*curr == s1) {
            curr = flst.insert_after(curr, s2);
            return;
        } else 
            ++curr;
    }
    if (mark == flst.end())
        flst.insert_after(curr, s2);
}
